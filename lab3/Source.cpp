#include <iostream>
#include <string>
#include "SurveyQuestion.h"
#include "SurveyQuestionVisitor.h"

#include "ChoiceQuestion.h"
#include "FreeQuestion.h"
#include "RangeQuestion.h"
#include "YesNoQuestion.h"
using namespace std;

void test1();

int main()
{
	test1();
	std::cin.get();
}

void test1()
{
	SurveyQuestionVisitor *visitorTXT = new SurveyQuestionTextDumpVisitor("text.txt");

	YesNoQuestion *questionYesNo = new YesNoQuestion("2+2=5?");
	questionYesNo->accept(*visitorTXT);

	FreeQuestion *questionFree = new FreeQuestion("whot you like?");
	questionFree->accept(*visitorTXT);

	RangeQuestion *range = new RangeQuestion(0,10,2,"4+2=");
	range->accept(*visitorTXT);

	vector<string> ans;
	ans.push_back("abc");
	ans.push_back("cab");
	ans.push_back("cad");
	ChoiceQuestion *choice = new ChoiceQuestion("taxi in london", ans);
	choice->accept(*visitorTXT);

	list <SurveyQuestion*> questions = visitorTXT->getQuestions();
	SurveyQuestionVisitor * consoleVisitor = new SurveyQuestionConsoleWriterVisitor();
	for (list <SurveyQuestion *>::iterator it = questions.begin(); it != questions.end(); ++it)
	{
		(*it)->accept(*consoleVisitor);
	}

}
