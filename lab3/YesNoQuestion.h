#pragma once
#include "SurveyQuestion.h"
class YesNoQuestion :
	public SurveyQuestion
{
public:
	YesNoQuestion() {}
	YesNoQuestion(string _question) :SurveyQuestion(_question){}
	~YesNoQuestion() {}

	int getAnswerCount(){return 2;}

	string getAnswer(int _number)
	{
		switch (_number)
		{
		case 0: {
			return "YES";
			break;
		}
		default: {
			return "NO";
		}
		}

	}
	
	void accept(SurveyQuestionVisitor & _in) { _in.visit(*this); }
};

