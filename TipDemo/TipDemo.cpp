#include "TipDemo.h"
#include "arrowwidget.h"

#include <qdebug.h>
#include <qlabel.h>
#include <qlineedit.h>

TipDemo::TipDemo(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    connect(ui.pushButton, &QPushButton::clicked,
        [this] {
            auto& aw = ArrowWidget::Instance();
            aw.setText(R"(愿我会揸火箭 带你到天空去
在太空中两人住
活到一千岁 都一般心醉
有你在身边多乐趣
共你双双对 好得戚好得意
地暗天崩当闲事
就算翻风雨 只需睇到你
似见阳光千万里
有了你开心啲 乜都称心满意
咸鱼白菜也好好味
我与你永共聚 分分钟需要你
你似是阳光空气
扮靓啲皆因你 癫癫地皆因你
为你甘心作傻事
扮下猩猩叫 睇到乜都笑
有你在身边多乐趣
若有朝失左你 花开都不美
愿到荒岛去长住
做个假的你 天天都相对
对木头公仔做戏
有了你开心啲乜都称心满意
咸鱼白菜也好好味
我与你永共聚 分分钟需要你
你似是阳光空气)");
            QRect rect = ui.pushButton->geometry();

            //aw.setDerection(ArrowWidget::up);
            //aw.setTriangleInfo(15, 10);
            //aw.myMove(mapToGlobal(QPoint(rect.x(), rect.y() + rect.height()))); // up

            //aw.setDerection(ArrowWidget::down);
            //aw.setTriangleInfo(15, 10);
            //aw.myMove(mapToGlobal(QPoint(rect.x(), rect.y()))); // down

            //aw.setDerection(ArrowWidget::left);
            //aw.setTriangleInfo(15, 10);
            //aw.myMove(mapToGlobal(QPoint(rect.x() + rect.width() , rect.y()))); // left

            aw.setDerection(ArrowWidget::right);
            aw.setTriangleInfo(15, 10);
            aw.myMove(mapToGlobal(QPoint(rect.x(), rect.y()))); // right

            aw.Show();
        });

    ui.label->installEventFilter(this);
}

bool TipDemo::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == ui.label) {
        if (event->type() == QEvent::ToolTip) {
            qDebug() << "hover enter";
            testToolTip();
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}

void TipDemo::testToolTip()
{
    auto& aw = ArrowWidget::Instance();
    aw.setText(R"(愿我会揸火箭 带你到天空去
在太空中两人住
活到一千岁 都一般心醉
有你在身边多乐趣
共你双双对 好得戚好得意
地暗天崩当闲事
就算翻风雨 只需睇到你
似见阳光千万里
有了你开心啲 乜都称心满意
咸鱼白菜也好好味
我与你永共聚 分分钟需要你
你似是阳光空气
扮靓啲皆因你 癫癫地皆因你
为你甘心作傻事
扮下猩猩叫 睇到乜都笑
有你在身边多乐趣
若有朝失左你 花开都不美
愿到荒岛去长住
做个假的你 天天都相对
对木头公仔做戏
有了你开心啲乜都称心满意
咸鱼白菜也好好味
我与你永共聚 分分钟需要你
你似是阳光空气)");
    QRect rect = ui.label->geometry();

	aw.setDerection(ArrowWidget::up);
	aw.setTriangleInfo(15, 10);
	aw.myMove(mapToGlobal(QPoint(rect.x(), rect.y() + rect.height()))); // up

    aw.Show();
}
