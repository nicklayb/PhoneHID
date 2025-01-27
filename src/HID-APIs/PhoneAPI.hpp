/*
Copyright (c) 2014-2015 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

// Include guard
#pragma once

PhoneAPI::PhoneAPI(void)
{
	// Empty
}

void PhoneAPI::begin(void){
	// release all buttons
	end();
}

void PhoneAPI::end(void){
	PhoneKeycode _report = HID_PHONE_UNASSIGNED;
	SendReport(&_report, sizeof(_report));
}

void PhoneAPI::write(PhoneKeycode p){
	press(p);
	release();
}

void PhoneAPI::release(void){
	begin();
}

void PhoneAPI::releaseAll(void){
	begin();
}

void PhoneAPI::press(PhoneKeycode p){
	SendReport(&p, sizeof(p));
}