#pragma once
#include "SurveyQuestion.h"
class FreeQuestion :
	public SurveyQuestion
{
public:
	FreeQuestion() {}
	FreeQuestion(string _question) :SurveyQuestion(_question){}
	~FreeQuestion() {}

	int getAnswerCount() { return 0; }
	string getAnswer(int _number) { return string(); }
	void accept(SurveyQuestionVisitor & _in) { _in.visit(*this); }
};

