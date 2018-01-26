#include "UrielImageViewer.h"
#include <QtWidgets>
#ifndef QT_NO_PRINTER
#include <QPrintDialog>
#endif
#include "UrielGui\CommonDialog\InformationDialog\InformationDialog.h"
UrielImageViewer::UrielImageViewer(QWidget *parent)
	: QDialog(parent)
	, imageLabel(new QLabel)
	, scaleFactor(1)
{
	ui.setupUi(this);
	initializeUI(parent);
	imageLabel->setBackgroundRole(QPalette::Base);
	imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	imageLabel->setScaledContents(true);

	ui.scrollArea->setBackgroundRole(QPalette::Dark);
	ui.scrollArea->setWidget(imageLabel);
	ui.scrollArea->setVisible(true);

	InitializeActions();
}

UrielImageViewer::~UrielImageViewer()
{
}


void UrielImageViewer::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
}

bool UrielImageViewer::loadFile(const QString &fileName)
{
	QImageReader reader(fileName);
	reader.setAutoTransform(true);
	const QImage newImage = reader.read();
	if (newImage.isNull()) {
		QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
			tr("Cannot load %1: %2")
			.arg(QDir::toNativeSeparators(fileName), reader.errorString()));
		return false;
	}
	setImage(newImage);

	setWindowFilePath(fileName);
	return true;
}

void UrielImageViewer::setImage(const QImage &newImage)
{
	image = newImage;
	imageLabel->setPixmap(QPixmap::fromImage(image));
	scaleFactor = 1.0;

	ui.scrollArea->setVisible(true);
	ui.printAct->setEnabled(true);
	ui.fitToWindowAct->setEnabled(true);
	updateActions();
	if (!ui.fitToWindowAct->isChecked())
		imageLabel->adjustSize();
	fitToWindow();
}


bool UrielImageViewer::saveFile(const QString &fileName)
{
	QImageWriter writer(fileName);

	if (!writer.write(image)) {
		QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
			tr("Cannot write %1: %2")
			.arg(QDir::toNativeSeparators(fileName)), writer.errorString());
		return false;
	}
	return true;
}


static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
	static bool firstDialog = true;

	if (firstDialog) {
		firstDialog = false;
		const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
		dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
	}

	QStringList mimeTypeFilters;
	const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
		? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
	foreach(const QByteArray &mimeTypeName, supportedMimeTypes)
		mimeTypeFilters.append(mimeTypeName);
	mimeTypeFilters.sort();
	dialog.setMimeTypeFilters(mimeTypeFilters);
	dialog.selectMimeTypeFilter("image/jpeg");
	if (acceptMode == QFileDialog::AcceptSave)
		dialog.setDefaultSuffix("jpg");
}

void UrielImageViewer::open()
{
	QFileDialog dialog(this, tr("Open File"));
	initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

	while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first())) {}
}

void UrielImageViewer::saveAs()
{
	QFileDialog dialog(this, tr("Save File As"));
	initializeImageFileDialog(dialog, QFileDialog::AcceptSave);

	while (dialog.exec() == QDialog::Accepted && !saveFile(dialog.selectedFiles().first())) {}
}

void UrielImageViewer::print()
{
	Q_ASSERT(imageLabel->pixmap());
#if !defined(QT_NO_PRINTER) && !defined(QT_NO_PRINTDIALOG)
	QPrintDialog dialog(&printer, this);
	if (dialog.exec()) {
		QPainter painter(&printer);
		QRect rect = painter.viewport();
		QSize size = imageLabel->pixmap()->size();
		size.scale(rect.size(), Qt::KeepAspectRatio);
		painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
		painter.setWindow(imageLabel->pixmap()->rect());
		painter.drawPixmap(0, 0, *imageLabel->pixmap());
	}
#endif
}

void UrielImageViewer::copy()
{
#ifndef QT_NO_CLIPBOARD
	QGuiApplication::clipboard()->setImage(image);
#endif 
}

#ifndef QT_NO_CLIPBOARD
static QImage clipboardImage()
{
	if (const QMimeData *mimeData = QGuiApplication::clipboard()->mimeData()) {
		if (mimeData->hasImage()) {
			const QImage image = qvariant_cast<QImage>(mimeData->imageData());
			if (!image.isNull())
				return image;
		}
	}
	return QImage();
}
#endif // !QT_NO_CLIPBOARD

void UrielImageViewer::paste()
{
#ifndef QT_NO_CLIPBOARD
	const QImage newImage = clipboardImage();
	if (newImage.isNull()) {
		InformationDialog dlg(QStringLiteral("信息"), QStringLiteral("粘贴板中无图像"),this);
		dlg.exec();
	}
	else {
		setImage(newImage);
		setWindowFilePath(QString());
	}
#endif // !QT_NO_CLIPBOARD
}


void UrielImageViewer::zoomIn()
{
	scaleImage(1.25);
}

void UrielImageViewer::zoomOut()
{
	scaleImage(0.8);
}

void UrielImageViewer::normalSize()
{
	imageLabel->adjustSize();
	scaleFactor = 1.0;
}

void UrielImageViewer::fitToWindow()
{
	bool fitToWindow = ui.fitToWindowAct->isChecked();
	ui.scrollArea->setWidgetResizable(fitToWindow);
	if (!fitToWindow)
		normalSize();
	updateActions();
}


void UrielImageViewer::InitializeActions()
{
	ui.openAct->setToolTip(QStringLiteral("打开"));
	connect(ui.openAct, &QToolButton::clicked, this, &UrielImageViewer::open);

	ui.saveAsAct->setToolTip(QStringLiteral("另存为")); 
	connect(ui.saveAsAct, &QToolButton::clicked, this, &UrielImageViewer::saveAs);
	ui.saveAsAct->setEnabled(false);

	ui.printAct->setToolTip(QStringLiteral("打印")); 
	connect(ui.printAct, &QToolButton::clicked, this, &UrielImageViewer::print);
	ui.printAct->setEnabled(false);

	ui.exitAct->setToolTip(QStringLiteral("关闭"));
	connect(ui.exitAct, &QToolButton::clicked, this, &UrielImageViewer::close);


	ui.copyAct->setToolTip(QStringLiteral("复制")); 
	connect(ui.copyAct, &QToolButton::clicked, this, &UrielImageViewer::copy);
	ui.copyAct->setEnabled(false);

	ui.pasteAct->setToolTip(QStringLiteral("粘贴"));
	connect(ui.pasteAct, &QToolButton::clicked, this, &UrielImageViewer::paste);


	ui.zoomInAct->setToolTip(QStringLiteral("放大(25%)"));
	connect(ui.zoomInAct, &QToolButton::clicked, this, &UrielImageViewer::zoomIn);
	ui.zoomInAct->setEnabled(false);

	ui.zoomOutAct->setToolTip(QStringLiteral("缩小(25%)")); 
	connect(ui.zoomOutAct, &QToolButton::clicked, this, &UrielImageViewer::zoomOut);
	ui.zoomOutAct->setEnabled(false);


	ui.normalSizeAct->setToolTip(QStringLiteral("正常模式")); 
	connect(ui.normalSizeAct, &QToolButton::clicked, this, &UrielImageViewer::normalSize);
	ui.normalSizeAct->setEnabled(false);

	ui.fitToWindowAct->setToolTip(QStringLiteral("适屏模式"));
	connect(ui.fitToWindowAct, &QToolButton::clicked, this, &UrielImageViewer::fitToWindow);
	ui.fitToWindowAct->setEnabled(false);
	ui.fitToWindowAct->setCheckable(true);
}

void UrielImageViewer::updateActions()
{
	ui.saveAsAct->setEnabled(!image.isNull());
	ui.copyAct->setEnabled(!image.isNull());
	ui.zoomInAct->setEnabled(!ui.fitToWindowAct->isChecked());
	ui.zoomOutAct->setEnabled(!ui.fitToWindowAct->isChecked());
	ui.normalSizeAct->setEnabled(!ui.fitToWindowAct->isChecked());
}

void UrielImageViewer::scaleImage(double factor)
{
	Q_ASSERT(imageLabel->pixmap());
	scaleFactor *= factor;
	imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

	adjustScrollBar(ui.scrollArea->horizontalScrollBar(), factor);
	adjustScrollBar(ui.scrollArea->verticalScrollBar(), factor);

	ui.zoomInAct->setEnabled(scaleFactor < 3.0);
	ui.zoomOutAct->setEnabled(scaleFactor > 0.333);
}

void UrielImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
	scrollBar->setValue(int(factor * scrollBar->value()
		+ ((factor - 1) * scrollBar->pageStep() / 2)));
}
