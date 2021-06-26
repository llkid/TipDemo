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
            aw.setText(R"(Ը�һ����� ���㵽���ȥ
��̫��������ס
�һǧ�� ��һ������
��������߶���Ȥ
����˫˫�� �õ��ݺõ���
�ذ����������
���㷭���� ֻ��������
�Ƽ�����ǧ����
�����㿪�Ć� ؿ����������
����ײ�Ҳ�ú�ζ
������������ �ַ�����Ҫ��
�������������
������������ ��ؽ�����
Ϊ�������ɵ��
�������ɽ� ����ؿ��Ц
��������߶���Ȥ
���г�ʧ���� ����������
Ը���ĵ�ȥ��ס
�����ٵ��� ���춼���
��ľͷ������Ϸ
�����㿪�Ć�ؿ����������
����ײ�Ҳ�ú�ζ
������������ �ַ�����Ҫ��
�������������)");
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
    aw.setText(R"(Ը�һ����� ���㵽���ȥ
��̫��������ס
�һǧ�� ��һ������
��������߶���Ȥ
����˫˫�� �õ��ݺõ���
�ذ����������
���㷭���� ֻ��������
�Ƽ�����ǧ����
�����㿪�Ć� ؿ����������
����ײ�Ҳ�ú�ζ
������������ �ַ�����Ҫ��
�������������
������������ ��ؽ�����
Ϊ�������ɵ��
�������ɽ� ����ؿ��Ц
��������߶���Ȥ
���г�ʧ���� ����������
Ը���ĵ�ȥ��ס
�����ٵ��� ���춼���
��ľͷ������Ϸ
�����㿪�Ć�ؿ����������
����ײ�Ҳ�ú�ζ
������������ �ַ�����Ҫ��
�������������)");
    QRect rect = ui.label->geometry();

	aw.setDerection(ArrowWidget::up);
	aw.setTriangleInfo(15, 10);
	aw.myMove(mapToGlobal(QPoint(rect.x(), rect.y() + rect.height()))); // up

    aw.Show();
}
