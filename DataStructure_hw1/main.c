#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*다음 조건을 만족하는 C 프로그램을 작성하시오.
- 이름(영어, 이름 성 순), 나이, 성별을 입력받아 이를 출력하는 프로그램. 단 이름의 출력은 성 이름의 순서가 되도록 해야함.
- 몇 명의 데이터가 입력될지 모르니, 이름에 stop이 입력되면 프로그램이 끝나도록 만듦 
- 포인터를 꼭 사용할 것.
- 다음의 프로그램 구조를 꼭 사용할 것. */

/*int main()
{
	struct {
		char name[50]; // 이름 
		int age;
		char sex;
		char* namep; // 성을 가리키는 포인터 
	} student;

	//programming going on 
	// 아래에 코드를 채워넣으세요. 
	
	
	for (;;)
	{
		printf("Provide your personal information \n");
		printf("Name : ");
		scanf("%[^\n]s", student.name); //공백포함 입력
		getchar(); // scanf 입력 버퍼제거
		
		//stop 입력시 종료
		if (strcmp(student.name, "stop") == 0)
		{
			break;
		}

		else
		{
			if (strrchr(student.name, ' ') != NULL)
			{
				student.namep = strrchr(student.name, ' ') + 1;
			}

			else
			{
				student.namep = 0;
				printf("잘못된 입력입니다\n");
				break;
			}

			printf("Age : ");
			scanf("%d", &student.age);
			getchar(); // scanf 입력 버퍼제거
			
			if (student.age < 0)
			{
				printf("잘못된 입력입니다.");
				break;
			}

			printf("Sex (M/F) : ");
			scanf("%c", &student.sex);
			getchar(); // scanf 입력 버퍼제거
			
			if (student.sex != 'M' && student.sex != 'F' && student.sex != 'f' && student.sex != 'm')
			{
				printf("잘못된 입력입니다.");
				break;
			}
			// strrchr함수를 이용해 문자열 오른쪽 부터 공백 부분까지의 문자열(성 부분)을 namep 포인터에 저장. 
			//strrchr사용 시 공백부분부터의 주솟값이 할당되므로 +1을 해서 문자부분부터의 주소값을 저장
			
			
			// strtok함수를 이용해 문자열 왼쪽부터 공백부분까지 문자열을 자름(이름부분), 
			//자른 부분은 null로 할당되므로 추후 %s로 struct.name 참조 시 이름부분 까지만 출력됨.
			strtok(student.name, " ");


			char result[200] = {0, }; // 결과출력 문자열 생성;
			sprintf(result, "Your name is %s %s, your age is %d, your sex is %c. \n", student.namep, student.name, student.age, student.sex);
			printf("%s", result);
		}
		printf("\n\n");

	}


	


	return 0;


}
*/ //이전

int main()
{
	struct {
		char name[50]; // 이름 
		int age;
		char sex;
		char* namep; // 성을 가리키는 포인터 
	} student;

	//programming going on 
	// 아래에 코드를 채워넣으세요. 

	int inputchk = 0;
	
	for (;;)
	{
		char* temp = (char*)malloc(sizeof(char) * 30);
		// 동적할당 // temp는 malloc으로 메모리 할당된 주소를 가리킴.
		if (!temp) return 0; else memset(temp, 0, 30);
		// sizeof(char)*30은 temp가 가리키는 곳의 메모리 크기를 30만큼 할당하라는 의미

		printf("\nProvide your personal information \n");
		printf("Name : ");
		inputchk = scanf(" %[^\n]s", student.name); //공백포함 입력

		//stop 입력시 종료
		if (strcmp(student.name, "stop") == 0)	{		break;    	}
		// strcmp -> 두 문자열 리터럴 비고 후 같으면 0 다르면 아스키코드 상 차이 반환(gcc)
		// visual studio -> 아스키 코드상 앞이 빠르면  1 앞이 느리면 -1 
		// 결론 그냥 > == < 차이만 기억하면 됨.

		if (strrchr(student.name, ' ') != NULL)
		{
			student.namep = strrchr(student.name, ' ') + 1;
			if (!temp) { printf("error");  break; }		else strcpy(temp, student.name);
			temp = strtok(temp, " ");
		}
		else
		{			student.namep = 0;			printf("wrong input\n");			continue;		}
		// strrchr함수를 이용해 문자열 오른쪽 부터 공백 부분까지의 문자열(성 부분)을 namep 포인터에 저장. 
		//strrchr사용 시 ' '을 인덱스로 설정 -> 공백부분부의 주솟값이 할당되므로 +1을 해서 문자열 끝의 '\0'까지의 주소값을 저장.
		// strtok함수를 이용해 문자열 왼쪽부터 공백부분까지 문자열을 자름(이름부분), 
		//자른 부분은 null로 할당되므로 추후 %s로 struct.name 참조 시 이름부분 까지만 출력됨.

		printf("Age : ");			
		inputchk = scanf(" %d", &student.age);
		if (inputchk == 0 && student.age < 0)		{			printf("wrong input\n");			continue;		}


		printf("Sex (M/F) : ");				inputchk = scanf(" %c", &student.sex);
		if (student.sex != 'M' && student.sex != 'F' && student.sex != 'f' && student.sex != 'm')
		{			printf("wrong input\n");			continue;		}

		char result[200] = { 0, }; // 결과출력 문자열 생성;
		sprintf(result, "Your name is %s %s, your age is %d, your sex is %c. \n", student.namep, temp, student.age, student.sex);
		//sprintf : 문자열로 저장하는 함수, (문자열 주소, "문자열 적을 것", 참조변수)
		printf("%s", result);

		if (!temp) { free(temp); }
	}

	return 0;
}
