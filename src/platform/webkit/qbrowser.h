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
	void navigateUrl(QUrl url);
};

#endif // QBROWSER_H
