// Copyright 2013-2016 Sandia Corporation. Under the terms
// of Contract DE-AC04-94AL85000 with Sandia Corporation, the U.S.
// Government retains certain rights in this software.
//
// Copyright (c) 2013-2016, Sandia Corporation
// All rights reserved.
//
// This file is part of the SST software package. For license
// information, see the LICENSE file in the top level directory of the
// distribution.

#ifndef COMPONENTS_FIREFLY_FUNCSM_SIZE_H
#define COMPONENTS_FIREFLY_FUNCSM_SIZE_H

#include "funcSM/api.h"
#include "event.h"

namespace SST {
namespace Firefly {

class SizeFuncSM :  public FunctionSMInterface
{
  public:
    SizeFuncSM( SST::Params& params ) : FunctionSMInterface( params ) {}

    virtual void handleStartEvent( SST::Event *e, Retval& retval ) {

        SizeStartEvent* event = static_cast< SizeStartEvent* >(e);

        m_dbg.verbose(CALL_INFO,1,0,"group=%d\n",event->group);

        assert( m_info->getGroup(event->group) );
        *event->size = m_info->getGroup(event->group)->getSize();

        retval.setExit(0);
        delete event;
    }
};

}
}

#endif