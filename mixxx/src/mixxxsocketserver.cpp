//
// C++ Implementation: mixxxsocketserver
//
// Description:
//
//
// Author: Tue Haste Andersen <haste@diku.dk>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "mixxxsocketserver.h"
#include "mixxxsocketclient.h"

MixxxSocketServer::MixxxSocketServer(Track *pTrack, QObject *parent, const char *name) : QServerSocket(QHostAddress(0x7f000001), 33033, 1, parent, name)
{
    m_pTrack = pTrack;

    if (!ok())
    {
        qWarning("Failed to bind to port 33033");
    }
}

MixxxSocketServer::~MixxxSocketServer()
{
}

void MixxxSocketServer::newConnection(int socket)
{
    MixxxSocketClient *s = new MixxxSocketClient(m_pTrack, socket, this);
}

