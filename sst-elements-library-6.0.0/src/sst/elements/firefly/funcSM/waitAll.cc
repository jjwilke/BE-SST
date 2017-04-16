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

#include <sst_config.h>

#include "funcSM/waitAll.h"

using namespace SST::Firefly;

WaitAllFuncSM::WaitAllFuncSM( SST::Params& params ) :
    FunctionSMInterface( params ),
    m_event( NULL )
{
}

void WaitAllFuncSM::handleStartEvent( SST::Event *e, Retval& retval ) 
{
    assert( NULL == m_event );
    m_dbg.verbose(CALL_INFO,1,0,"\n");

    m_event = static_cast< WaitAllStartEvent* >(e);

    proto()->waitAll( m_event->count, m_event->req, m_event->resp );
}

void WaitAllFuncSM::handleEnterEvent( Retval& retval )
{
    m_dbg.verbose(CALL_INFO,1,0,"\n");
    retval.setExit(0);
    delete m_event;
    m_event = NULL;
}
