#include "arrowwidget.h"

#include <QLabel>
#include <QLayout>
#include <QVariant>
#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QTimer>

ArrowWidget::ArrowWidget(QWidget *parent) : QWidget(parent)
  , m_offset(10)
  , m_triangleWidth(TRIANGLE_WIDTH)
  , m_triangleHeight(TRIANGLE_HEIGHT)
    , derect(Derection::up)
{
    setWindowFlags(Qt::FramelessWindowHint
                   | Qt::Tool
                   | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QHBoxLayout* hMainLayout = new QHBoxLayout;
    setLayout(hMainLayout);

    lb_text = new QLabel(this);
    //lb_text->setProperty("class", "font12px");

    lb_text->setWordWrap(true);
    lb_text->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    lb_text->setFixedWidth(244);
    lb_text->setStyleSheet(R"(
                           padding: 12px 12px 12px 12px;
                           font-size: 12px;
                           font-family: "微软雅黑";
                           color: white;
                           )");
    hMainLayout->addWidget(lb_text);
    hMainLayout->setContentsMargins(LEFT_MARGIN, TOP_MARGIN, RIGHT_MARGIN, BOTTOM_MARGIN);
}

ArrowWidget::~ArrowWidget()
{

}

ArrowWidget &ArrowWidget::Instance()
{
    static ArrowWidget instance;
    return instance;
}

void ArrowWidget::setStartPos(int startX)
{
    this->m_offset = startX;
    this->repaint();
}

void ArrowWidget::setTriangleInfo(int width, int height)
{
    m_triangleWidth = width;
    m_triangleHeight = height;
    this->layout()->setContentsMargins(height, height, height, height);
}

void ArrowWidget::setText(QString s)
{
    lb_text->setText(s);
    this->adjustSize();
}

void ArrowWidget::setDerection(ArrowWidget::Derection d)
{
    this->derect = d;
}

QString ArrowWidget::text() const
{
    return lb_text->text();
}

void ArrowWidget::myMove(QPoint&& point)
{
    int x;
    int y;
    switch (derect)
    {
    case ArrowWidget::left:
        x = point.x();
        y = point.y() - m_triangleHeight;
        break;
    case ArrowWidget::right:
        x = point.x() - width();
        y = point.y() - m_triangleHeight;
        break;
    case ArrowWidget::up:
        x = point.x() - m_triangleHeight;
        y = point.y();
        break;
    case ArrowWidget::down:
        x = point.x() - m_triangleHeight;
        y = point.y() - height();
        break;
    default:
        return;
    }
    this->move(x, y);
}

void ArrowWidget::Show()
{
    if (this->isHidden()) {
        this->show();
    }
}

void ArrowWidget::Hide()
{
    QTimer::singleShot(300, Qt::PreciseTimer, [this] {this->hide(); });
}

void ArrowWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(51, 51, 51, 255));

    QPainterPath drawPath;
    // 小三角区域;
    QPolygon trianglePolygon;

    QRect myRect(lb_text->x(), lb_text->y(), lb_text->width(), lb_text->height());

    // 设置小三的具体位置
    int tri_pos_x, tri_pos_y;
    switch (derect)
    {
    case up:{
        // 小三角左边的点的位置
        tri_pos_x = myRect.x() + m_offset;
        tri_pos_y = myRect.y();
        trianglePolygon << QPoint(tri_pos_x, tri_pos_y);
        trianglePolygon << QPoint(tri_pos_x + m_triangleWidth, tri_pos_y);
        trianglePolygon << QPoint(tri_pos_x + m_triangleWidth / 2, tri_pos_y - m_triangleHeight);
    }
        break;
    case left:{
        // 小三上边点的位置
        tri_pos_x = myRect.x();
        tri_pos_y = myRect.y() + m_offset;
        trianglePolygon << QPoint(tri_pos_x, tri_pos_y);
        trianglePolygon << QPoint(tri_pos_x - m_triangleHeight, tri_pos_y + m_triangleWidth / 2);
        trianglePolygon << QPoint(tri_pos_x, tri_pos_y + m_triangleWidth);
    }
        break;
    case right:{
        // 小三上边点的位置
        tri_pos_x = myRect.x() + myRect.width();
        tri_pos_y = myRect.y() + m_offset;
        trianglePolygon << QPoint(tri_pos_x, tri_pos_y);
        trianglePolygon << QPoint(tri_pos_x + m_triangleHeight, tri_pos_y + m_triangleWidth / 2);
        trianglePolygon << QPoint(tri_pos_x, tri_pos_y + m_triangleWidth);
    }

        break;
    case down:{
        // 小三左边点的位置
        tri_pos_x = myRect.x() + m_offset;
        tri_pos_y = myRect.y() + myRect.height();
        trianglePolygon << QPoint(tri_pos_x, tri_pos_y);
        trianglePolygon << QPoint(tri_pos_x + m_triangleWidth / 2, tri_pos_y + m_triangleHeight);
        trianglePolygon << QPoint(tri_pos_x + m_triangleWidth, tri_pos_y);
    }
        break;
    default:
        break;
    }
    drawPath.addRoundedRect(myRect, BORDER_RADIUS, BORDER_RADIUS);
    drawPath.addPolygon(trianglePolygon);
    painter.drawPath(drawPath);
}

void ArrowWidget::mousePressEvent(QMouseEvent *)
{
    this->close();
}
