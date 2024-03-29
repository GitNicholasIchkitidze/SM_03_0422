/*
	2  * Copyright (C) 2012 Southern Storm Software, Pty Ltd.
	3  *
	4  * Permission is hereby granted, free of charge, to any person obtaining a
	5  * copy of this software and associated documentation files (the "Software"),
	6  * to deal in the Software without restriction, including without limitation
	7  * the rights to use, copy, modify, merge, publish, distribute, sublicense,
	8  * and/or sell copies of the Software, and to permit persons to whom the
	9  * Software is furnished to do so, subject to the following conditions:
   10  *
   11  * The above copyright notice and this permission notice shall be included
   12  * in all copies or substantial portions of the Software.
   13  *
   14  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   15  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   16  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   17  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   18  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   19  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   20  * DEALINGS IN THE SOFTWARE.
   21  */
	
	 #ifndef I2CMaster_h
	 #define I2CMaster_h
	
	 #include <inttypes.h>
	
	 class I2CMaster {
	 public:
		     virtual unsigned int maxTransferSize() const = 0;
		
			     virtual void startWrite(unsigned int address);
		     virtual void write(uint8_t value) = 0;
		     virtual bool endWrite() = 0;
		
			     virtual bool startRead(unsigned int address, unsigned int count) = 0;
		     virtual unsigned int available() = 0;
		     virtual uint8_t read() = 0;
		
};

 #endif
