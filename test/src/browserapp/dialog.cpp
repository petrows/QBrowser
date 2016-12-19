#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);

	ui->widget->navigateUrl(QUrl("https://m.vk.com/"));
	connect(ui->widget, &QBrowser::onLoadFinished, this, &Dialog::slotLoadFinished);
	connect(ui->widget, &QBrowser::onUrlChanged, this, &Dialog::slotUrlChanged);
}

Dialog::~Dialog()
{
	delete ui;
}

void Dialog::slotLoadFinished(bool isOk)
{
	qDebug() << "Load finished! Result is " << isOk;
}

void Dialog::slotUrlChanged(QUrl url)
{
	qDebug() << "New URL: " << url;
}
