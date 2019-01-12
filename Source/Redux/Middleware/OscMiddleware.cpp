#include "OscMiddleware.h"

OscMiddleware::OscMiddleware()
{
	connect(9001);

	addListener(this, "/test");
}

ActionObject OscMiddleware::dispatch(const ActionObject &action, Store &store) {

	  auto n = next.lock();
	  auto result = n ? n->dispatch(action, store) : action;
	  return result;
  }

  void OscMiddleware::oscMessageReceived(const OSCMessage & message)
  {
  }
