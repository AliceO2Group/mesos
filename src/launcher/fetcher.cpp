// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "do_fetcher.hpp"

// This "fetcher program" is invoked by the slave's fetcher actor
// (Fetcher, FetcherProcess) to "fetch" URIs into the sandbox directory
// of a given task. Its parameters are provided in the form of the env
// var MESOS_FETCHER_INFO which contains a FetcherInfo (see
// fetcher.proto) object formatted in JSON. These are set by the actor
// to indicate what set of URIs to process and how to proceed with
// each one. A URI can be downloaded directly to the task's sandbox
// directory or it can be copied to a cache first or it can be reused
// from the cache, avoiding downloading. All cache management and
// bookkeeping is centralized in the slave's fetcher actor, which can
// have multiple instances of this fetcher program running at any
// given time. Exit code: 0 if entirely successful, otherwise 1.
int main(int argc, char* argv[])
{
  return do_fetcher(argc, argv);
}
