#ifndef QBROWSERBASE_H
#define QBROWSERBASE_H

#include <QWidget>
#include <QUrl>

class QBrowserBase : public QWidget
{
	Q_OBJECT
public:
	explicit QBrowserBase(QWidget *parent = 0);

	//! Navigate to desired URL
	virtual void navigateUrl(QUrl url) = 0;

signals:
	//! Signal emits when new URL loaded (by redirect or direct command)
	void onUrlChanged();

public slots:
};

#endif // QBROWSERBASE_H
