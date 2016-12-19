#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QUrl>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog(QWidget *parent = 0);
	~Dialog();

private slots:
	void slotLoadFinished(bool isOk);
	void slotUrlChanged(QUrl url);

private:
	Ui::Dialog *ui;
};

#endif // DIALOG_H
