#ifndef QBROWSER_H
#define QBROWSER_H

#include <qbrowserbase.h>

class QBrowser : public QBrowserBase
{
	Q_OBJECT
public:
	explicit QBrowser(QWidget *parent = 0);

signals:

public slots:

	// QBrowserBase interface
public:
	void navigateUrl(const QUrl &url);

private slots:
	void unsupportedContent(QNetworkReply*);
};

#endif // QBROWSER_H
