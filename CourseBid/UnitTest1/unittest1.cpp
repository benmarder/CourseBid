#include "stdafx.h"
#include "CppUnitTest.h"
#include "FileStorage.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CourseBidTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethodStudentStorage)
		{
			Student* s1 = new Student();
			s1->setId("s01");
			FileStorage* fs = FileStorage::getInstance();
			fs->setStudent(s1);
			Student* s2 = fs->getStudent(s1->getId(), false, "");
			Assert::AreEqual(s1->getId(), s2->getId());
		}

		TEST_METHOD(TestMethodCourseStorage)
		{
			Course* c1 = new Course();
			c1->setId("c01");
			FileStorage* fs = FileStorage::getInstance();
			fs->setCourse(c1);
			Course* c2 = fs->getCourse(c1->getId());
			Assert::AreEqual(c1->getId(), c2->getId());
		}
		TEST_METHOD(TestMethodTerminalStorage)
		{
			Terminal* t1 = new Terminal();
			t1->setId("t01");
			FileStorage* fs = FileStorage::getInstance();
			fs->setTerminal(t1);
			Terminal* t2 = fs->getTerminal(t1->getId());
			Assert::AreEqual(t1->getId(), t2->getId());
		}

	};

	TEST_CLASS(UnitTest2)
	{
		TEST_METHOD(TestMethodCoursegetName)
		{
			Course c;
			string name = "math";
			c.setName(name);
			Assert::AreEqual(c.getName(), name);
		}
		TEST_METHOD(TestMethodCoursegetId)
		{
			Course c;
			string id = "S01";
			c.setId(id);
			Assert::AreEqual(c.getId(), id);
		}
		TEST_METHOD(TestMethodCoursegetHours)
		{
			Course c;
			int hours = 5;
			c.setHoures(hours);
			Assert::AreEqual(c.getHours(), hours);
		}
	};
}