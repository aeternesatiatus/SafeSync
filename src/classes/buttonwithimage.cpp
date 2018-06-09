#include "buttonwithimage.h"

ButtonWithImage::ButtonWithImage(QString image, QString text, QWidget *parent, ImageAlignment img_align, ButtonShape bt_shape):
    QPushButton(text, parent),
    m_img_align(img_align),
    m_bt_shape(bt_shape),
    hostButton(new QPushButton(text, this)),
    m_image_pixmap(new QPixmap(image)),
    imagePath(image),
    aspectRatio(m_image_pixmap->width()/m_image_pixmap->height())
{
    hostButton->lower();
}

ButtonWithImage::~ButtonWithImage()
{
    delete m_image_pixmap;
}

void ButtonWithImage::resizeEvent(QResizeEvent *event)
{
    (void)event;
    updateShape();
    updateImage();
    hostButton->resize(size());
}

void ButtonWithImage::paintEvent(QPaintEvent *event)
{
    (void)event;

    QPainter painter(this);

    switch (m_img_align) {
    case RightAlignment:
        painter.drawPixmap(width()-img_size.width(), 0, *m_image_pixmap);
        break;
    case LeftAlignment:
        painter.drawPixmap(0, 0, *m_image_pixmap);
        break;
    }
}

void ButtonWithImage::updateShape()
{
    switch (m_bt_shape) {
    case RoundShape:
        setStyleSheet("border-radius: " + QString::number(int(height()/2)) + ";");
        break;
    default:
        break;
    }
}

void ButtonWithImage::updateImage()
{
    img_size = computeSize(width(), height());

    *m_image_pixmap = m_image_pixmap->scaled(img_size);
}

QSize ButtonWithImage::computeSize(int maxwidth, int maxheight)
{
    QSize returnValue;

    switch (maxwidth>maxheight) {
    case true:
        returnValue.setHeight(maxheight);
        returnValue.setWidth(maxheight * aspectRatio);
        break;
    case false:
        returnValue.setWidth(maxwidth);
        returnValue.setHeight(maxwidth / aspectRatio);
        break;
    }

    return returnValue;
}

/*
 * r = w / h
 * w = r * h
 * h = w / r
 */
