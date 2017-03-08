#pragma once
#include <string>
#include <iostream>
#include <list>

class YesNoQuestion;
class RangeQuestion;
class FreeQuestion;
class ChoiceQuestion;
class SurveyQuestion;

using namespace std;

class SurveyQuestionVisitor
{
protected:
	string file;
	
public:
	virtual void visit(ChoiceQuestion &ref) = 0;
	virtual void visit(FreeQuestion & ref) = 0;
	virtual void visit(RangeQuestion & ref) = 0;
	virtual void visit(YesNoQuestion & ref) = 0;

	virtual list<SurveyQuestion *> getQuestions()=0;
};

class SurveyQuestionBinarySerializationVisitor :public SurveyQuestionVisitor
{
public:
	SurveyQuestionBinarySerializationVisitor() = delete;
	SurveyQuestionBinarySerializationVisitor(string _file);
	~SurveyQuestionBinarySerializationVisitor();

	void visit(ChoiceQuestion &ref);
	void visit(FreeQuestion & ref);
	void visit(RangeQuestion & ref);
	void visit(YesNoQuestion & ref);

	list<SurveyQuestion*> getQuestions();
};

class SurveyQuestionTextDumpVisitor :public SurveyQuestionVisitor
{

public:
	SurveyQuestionTextDumpVisitor() = delete;
	SurveyQuestionTextDumpVisitor(string _file);
	~SurveyQuestionTextDumpVisitor();

	void visit(ChoiceQuestion &ref);
	void visit(FreeQuestion & ref);
	void visit(RangeQuestion & ref);
	void visit(YesNoQuestion & ref);

	list<SurveyQuestion*> getQuestions() ;
};

class SurveyQuestionConsoleWriterVisitor :public SurveyQuestionVisitor
{
private:
	list <SurveyQuestion*> listQ;
public:
	SurveyQuestionConsoleWriterVisitor() {}
	SurveyQuestionConsoleWriterVisitor(string _file) = delete;
	~SurveyQuestionConsoleWriterVisitor();

	void visit(ChoiceQuestion &ref) ;
	void visit(FreeQuestion & ref) ;
	void visit(RangeQuestion & ref);
	void visit(YesNoQuestion & ref);

	list<SurveyQuestion *> getQuestions() ;
};