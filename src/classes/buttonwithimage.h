#ifndef BUTTONWITHIMAGE_H
#define BUTTONWITHIMAGE_H

#include <QPushButton>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QSize>
#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QPainter>

class ButtonWithImage : public QPushButton
{
    Q_OBJECT
public:
    enum ImageAlignment {
        RightAlignment, LeftAlignment
    };

    enum ButtonShape {
        DefaultShape, RoundShape
    };

    ButtonWithImage(QString image, QString text, QWidget *parent = 0, ImageAlignment img_align = RightAlignment, ButtonShape bt_shape = DefaultShape);
    ~ButtonWithImage();

private:
    ImageAlignment m_img_align;
    ButtonShape m_bt_shape;

    QPushButton *hostButton;
    QPixmap *m_image_pixmap;
    QString imagePath;

    double aspectRatio;

    QSize img_size;

    QSize computeSize(int maxwidth, int maxheight);

private slots:
    void updateShape();
    void updateImage();

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

};

#endif // BUTTONWITHIMAGE_H
