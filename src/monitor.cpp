#include "monitor.h"

Monitor* monitor;

Monitor::Monitor(QWidget *parent) : QTextEdit(parent) {

    this->setReadOnly(true);

    connect(search,
            SIGNAL(sig_summery(Summery*)),
            this, SLOT(slt_summery(Summery*)),
            Qt::QueuedConnection);

    this->setFont(QFont("Monaco"));

}

void Monitor::slt_summery(Summery *_sum) {
    qDebug() << "DDDDD";
    this->setTextColor(Qt::red);
    this->append(" -- BUILD SUMMERY --");
    this->setTextColor(Qt::blue);
    this->append(QString(" Tree Name : ") + _sum->treeName);
    this->setTextColor(Qt::black);
    this->append(QString(" Tree Size       --> %1").arg(_sum->treeSize));
    this->append(QString(" Files Count     --> %1").arg(_sum->filesCount));
    this->append(QString(" Words Count     --> %1").arg(_sum->wordsCount));
    this->append(QString(" Time That Takes --> %1").arg(_sum->timeTakesToBuild));
    this->setTextColor(Qt::red);
    this->append(" -- BUILD SUMMERY ENDS --");
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->maximum());
}
