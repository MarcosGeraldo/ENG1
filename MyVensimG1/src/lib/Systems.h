#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include "SystemsImpl.h"

using namespace std;

class Systems{

public:
  	/** System destructor */
	virtual ~Systems();
  	/** Declare Systems with 2 parameters as string and double types */
  virtual void System(string, double) = 0;
  	/** Declare Systems that points to systems on the class Systems  */
  virtual void System(Systems* systems) = 0;
  	/** Get the name */
  virtual string getName(void) = 0;
    	/** Get the content */
  virtual double getContent() = 0;
	/** Change the name as a string type */
  virtual void setName(string) = 0;
  	/** Change the content as a double type */
  virtual void setContent(double) = 0;
	/** Increases the value as a double type */
  virtual void increase(double) = 0;
  		/** Decreases the value as a double type */
  virtual void decrease(double) = 0;
};

#endif
