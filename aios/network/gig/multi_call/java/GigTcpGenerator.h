/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ISEARCH_MULTI_CALL_GIGTCPGENERATOR_H
#define ISEARCH_MULTI_CALL_GIGTCPGENERATOR_H

#include "aios/network/gig/multi_call/common/common.h"
#include "aios/network/gig/multi_call/java/GigRequestGenerator.h"
#include "aios/network/gig/multi_call/java/GigTcpRequest.h"
#include "aios/network/gig/multi_call/proto/GigCallProto.pb.h"

namespace multi_call {

class GigTcpGenerator : public GigRequestGenerator
{
public:
    GigTcpGenerator(const std::string &clusterName, const std::string &bizName,
                    const std::shared_ptr<google::protobuf::Arena> &arena =
                        std::shared_ptr<google::protobuf::Arena>())
        : GigRequestGenerator(clusterName, bizName, arena) {
    }
    ~GigTcpGenerator() {
    }

private:
    GigTcpGenerator(const GigTcpGenerator &);
    GigTcpGenerator &operator=(const GigTcpGenerator &);

private:
    RequestPtr generateRequest(const std::string &bodyStr,
                               const GigRequestPlan &requestPlan) override;

private:
    AUTIL_LOG_DECLARE();
};

MULTI_CALL_TYPEDEF_PTR(GigTcpGenerator);

} // namespace multi_call

#endif // ISEARCH_MULTI_CALL_GIGTCPGENERATOR_H
