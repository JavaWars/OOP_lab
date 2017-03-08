#pragma once
#include "SurveyQuestion.h"
#include <string>
#include <vector>
using namespace std;
class ChoiceQuestion :
	public SurveyQuestion
{
private :
	vector<string> answers;
public:
	ChoiceQuestion() {}
	ChoiceQuestion(string _question, vector<string> _answers) :SurveyQuestion(_question) { answers = _answers; }
	~ChoiceQuestion() {}

	int getAnswerCount() { return answers.size(); }
	
	string getAnswer(int _number) {
		if (_number < answers.size())
		{
			return answers[_number];
		}
		return "";
	}
	
	void accept(SurveyQuestionVisitor & _in) { _in.visit(*this); }
};

