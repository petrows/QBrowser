#ifndef QBROWSERBASE_H
#define QBROWSERBASE_H

#include <QWidget>
#include <QUrl>

#include <qbrowser_config.h>

class QBrowserBase : public QBROWSER_BASE
{
	Q_OBJECT
public:
	explicit QBrowserBase(QWidget *parent = 0) {}

signals:
	//! Signal emits when new URL loaded (by redirect or direct command)
	void onUrlChanged(QUrl url);
	void onLoadProgress(int progressPersent);
	void onLoadFinished(bool loadOk);
	void onLoadStarted();

public slots:
	//! Navigate to desired URL
	virtual void navigateUrl(const QUrl &url) = 0;

};

#endif // QBROWSERBASE_H
