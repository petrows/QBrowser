#include "qbrowser.h"

QBrowser::QBrowser(QWidget *parent)
{
	connect(this, &QWebView::urlChanged, this, &QBrowser::onUrlChanged);
	connect(this, &QWebView::loadProgress, this, &QBrowser::onLoadProgress);
	connect(this, &QWebView::loadFinished, this, &QBrowser::onLoadFinished);
	connect(this, &QWebView::loadStarted, this, &QBrowser::onLoadStarted);
}

void QBrowser::navigateUrl(const QUrl &url)
{
	setUrl(url);
}

void QBrowser::unsupportedContent(QNetworkReply *)
{
	// Do nothing
}
