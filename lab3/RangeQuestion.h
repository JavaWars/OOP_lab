#pragma once
#include "SurveyQuestion.h"
class RangeQuestion :
	public SurveyQuestion
{
private :
	int start, finish, step;
public:
	RangeQuestion(){}
	RangeQuestion(int _start, int _finish, int _step,string _question) :SurveyQuestion(_question) ,start(_start), finish(_finish), step(_step) {}
	~RangeQuestion() {}

	int getAnswerCount() { return (( finish- start) / step); }
	int getStart() { return start; }
	int getFinish() { return finish; }
	int getStep() { return step; }

	string getAnswer(int _number)
	{
		int result = (start + _number*(step));
		return std::to_string(result);
	}
	
	void accept(SurveyQuestionVisitor & _in) { _in.visit(*this); }
};

