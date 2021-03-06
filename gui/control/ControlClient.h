/* Copyright (C) 2015-2016 Alexander Shishenko <GamePad64@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <QWebSocket>
#include <QJsonObject>
#include "pch.h"

class ControlClient : public QWebSocket {
Q_OBJECT

public:
	ControlClient();
	~ControlClient();

signals:
	void ControlJsonReceived(QJsonObject control_json);

public slots:
	void connectDaemon(const QUrl& daemon_address);

	void sendControlJson(QJsonObject control_json);
	void sendConfigJson(QJsonObject config_json);
	void sendAddFolderJson(QString secret, QString path);
	void sendRemoveFolderJson(QString secret);

private slots:
	void handle_message(const QString& message);
	void handle_connect();
	void handle_disconnect();

private:
	QUrl daemon_address_;
};
