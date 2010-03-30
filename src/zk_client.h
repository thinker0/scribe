//  Copyright (c) 2007-2008 Facebook
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
// See accompanying file LICENSE or visit the Scribe site at:
// http://developers.facebook.com/scribe/
//
// @author Travis Crawford <travis@twitter.com>

#ifndef SCRIBE_ZK_CLIENT_H
#define SCRIBE_ZK_CLIENT_H

#ifdef USE_ZOOKEEPER
#include "common.h"
#include "scribe_server.h"

void watcher(zhandle_t *zzh, int type, int state,
             const char *path, void *watcherCtx);

class ZKClient {
 public:
   ZKClient(std::string& hostPort,
            std::string& zkRegistrationPrefix,
            unsigned long int handlerPort);
   virtual ~ZKClient();

   bool connect();
   bool registerTask();
   bool isRegistered();
   bool getRemoteScribe(std::string& parentZnode,
                        std::string& remoteHost,
                        unsigned long& remotePort);

   zhandle_t *zh; // Zookeeper connection handle.
   std::string zkHostPort; // Zookeeper server host:port
   std::string zkRegistrationPrefix; // In `/zk/path/name' format.
   std::string zkRegistrationName; // In `hostname:port' format.
   std::string zkFullRegistrationName;
   unsigned long int port;
};

extern ZKClient* g_ZKClient;

#endif // SCRIBE_ZK_CLIENT_H
#endif // USE_ZOOKEEPER