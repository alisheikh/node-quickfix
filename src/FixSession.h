/*
 * FixSession.h
 *
 *  Created on: Sep 16, 2014
 *      Author: kdeol
 */

#ifndef FIXSESSION_H_
#define FIXSESSION_H_

#include <v8.h>
#include <node.h>
#include <nan.h>

#include "quickfix/Session.h"

using namespace v8;
using namespace node;

class FixSession : public node::ObjectWrap {
public:
	FixSession();
	static void Initialize(v8::Handle<v8::Object> target);
	static NAN_METHOD(New);
	void setSession(FIX::Session* session);
	static Handle<Object> wrapFixSession(FixSession* fixSession);

private:
	virtual ~FixSession();
	FIX::Session* mSession;
	static NAN_METHOD(isEnabled);
	static NAN_METHOD(logon);
	static NAN_METHOD(logout);
	static NAN_METHOD(isLoggedOn);
	static NAN_METHOD(getSessionID);
	static NAN_METHOD(disconnect);
};

#endif /* FIXSESSION_H_ */
