#pragma once

#include <QtWidgets/QWidget>
#include "ui_TipDemo.h"

class TipDemo : public QWidget
{
    Q_OBJECT

public:
    TipDemo(QWidget *parent = Q_NULLPTR);

protected:
    bool eventFilter(QObject* watched, QEvent* event) override;

private:
    Ui::TipDemoClass ui;

private:
    void testToolTip();
};
