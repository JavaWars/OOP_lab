#pragma once
#include <string>
using namespace std;

class SurveyQuestionVisitor;

class SurveyQuestion
{
protected:
	string question;
	SurveyQuestion() {}
	SurveyQuestion(string questionText) { question = questionText; }
	~SurveyQuestion() {}
public:
	virtual int getAnswerCount()=0;
	virtual string getAnswer(int _number) = 0;
	virtual void accept(SurveyQuestionVisitor & _in) = 0;
	string getQuestion() { return question; }
};

