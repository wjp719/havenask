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
#ifndef MASTER_FRAMEWORK_PARTITIONSCHEDULEUNITFACTORY_H
#define MASTER_FRAMEWORK_PARTITIONSCHEDULEUNITFACTORY_H

#include "master_framework/common.h"
#include "master_framework/PartitionScheduleUnit.h"
#include "master_framework/ScheduleUnitFactory.h"

BEGIN_MASTER_FRAMEWORK_NAMESPACE(master_base);

class PartitionScheduleUnitFactory : public ScheduleUnitFactory
{
public:
    PartitionScheduleUnitFactory();
    ~PartitionScheduleUnitFactory();
private:
    PartitionScheduleUnitFactory(const PartitionScheduleUnitFactory &);
    PartitionScheduleUnitFactory& operator=(const PartitionScheduleUnitFactory &);
public:
    /* override */ ScheduleUnitPtr createScheduleUnit(
            const std::string &name,
            hippo::MasterDriver *hippoMasterDriver);
};

MASTER_FRAMEWORK_TYPEDEF_PTR(PartitionScheduleUnitFactory);

END_MASTER_FRAMEWORK_NAMESPACE(master_base);

#endif //MASTER_FRAMEWORK_PARTITIONSCHEDULEUNITFACTORY_H
