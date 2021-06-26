#ifndef ARROWWIDGET_H
#define ARROWWIDGET_H

#include <QWidget>

#pragma execution_character_set("utf-8")

#define SHADOW_WIDTH  30               // 窗口阴影宽度
#define TRIANGLE_WIDTH  15             // 小三角的宽度
#define TRIANGLE_HEIGHT  10            // 小三角的高度
#define BORDER_RADIUS  0               // 窗口边角的弧度
#define LEFT_MARGIN  10                // 左边衬
#define RIGHT_MARGIN  10               // 右边衬
#define TOP_MARGIN  10                 // 顶边衬
#define BOTTOM_MARGIN  10              // 底边衬

class QLabel;

class ArrowWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ArrowWidget)

    explicit ArrowWidget(QWidget *parent = nullptr);
public:
    enum Derection {
        left,
        right,
        up,
        down
    };

    ~ArrowWidget();
    static ArrowWidget &Instance();

    // 设置小三角起始位置;
    void setStartPos(int startX);
    // 设置小三角宽和高;
    void setTriangleInfo(int width, int height);
    // 设置展示文本
    void setText(QString s);
    // 设置小三角的位置
    void setDerection(Derection d);
    //
    QString text() const;
    // 比起左上角的位置  用户更关心小三角的尖尖的位置 重载move以便用户更容易定位气泡框的位置
    void myMove(QPoint&& point);

    void Show();

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent (QMouseEvent *) override;

private:
    // 小三角的偏移量;
    int m_offset;
    // 小三角的宽度;
    int m_triangleWidth;
    // 小三角高度;
    int m_triangleHeight;
    Derection derect;
    QLabel *lb_text;

signals:

};

#endif // ARROWWIDGET_H
