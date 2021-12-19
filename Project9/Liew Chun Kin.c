#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//constant
#define LOVEPRICE 25.00
#define NUTPRICE 20.00
#define ASSORTEDPRICE 15.00
#define DISCOUNT1 0.05
#define DISCOUNT2 0.10
#define MEMBERDISCOUNT 0.15

//function
void order();
void discount();
void start();
void nextorder();
void orderconfirm();
void menu();
void member();

//declare order note's variable
int num1, num2, num3, orderNo, dd, yy, mm;
char yesorno, phone[15];
float no1, no2, no3, sub1, total, discountget, amountPay, deposit, balance, memberdiscount;

//declare order summary's variable
int tnum1 = 0, tnum2 = 0, tnum3 = 0, tOrderNo = 0;
float tno1 = 0, tno2 = 0, tno3 = 0, tSales = 0, tDiscount = 0, tMemberDiscount = 0, tNetSales = 0, tDeposit = 0, tBalance = 0;

void main()
{
	start();

	while (yesorno != 'y' && yesorno != 'Y')
	{
		system("cls");
		start();
	}

	while (yesorno == 'y' || yesorno == 'Y')
	{
		order();
	}

}

void start()
{
	//logo
	printf("          \t===================== \n");
	printf("          \t|                   | \n");
	printf("          \t| ******   *        | \n");
	printf("          \t| *     *  *        | \n");
	printf("          \t| *     *  *        | \n");
	printf("          \t| *     *  *        | \n");
	printf("          \t| ******   ******   | \n");
	printf("          \t|                   | \n");
	printf("          \t===================== \n");


	//tarc cooking ordering system
	printf("\n\n******       **          *****        *    *          ******");
	printf("\n  *         *  *         *    *       *    *         *");
	printf("\n  *        *    *        *   *        *    *         *");
	printf("\n  *       ********       ****         *    *         *");
	printf("\n  *      *        *      *   *        *    *         *");
	printf("\n  *     *          *     *    *        ****          ******* \n\n");
	printf("COOKIES ORDERING SYSTEM\n");

	printf("You are welcome to ordering cookies!\n");

	printf("Pls enter today's date (dd/mm/yyyy) :");
	scanf("%d/%d/%d", &dd, &mm, &yy);
	rewind(stdin);

	printf("Pls enter your phone number (without '-') :");
	scanf("%s", &phone);
	rewind(stdin);

	system("cls");

	menu();
}
void menu()
{
	printf("                 Menu\n"); //display menu
	printf("============================================\n");
	printf("Love Letters Cookies (per tin) = RM 25.00\n");
	printf("Nut Cookies          (per jar) = RM 20.00\n");
	printf("Assorted Cookies     (per jar) = RM 15.00\n");
	printf("============================================\n");

	printf("               Discount\n"); //display discount
	printf("****************************************************************\n");
	printf("Customers with member cards will get 15%% discount ");
	printf("\nOrders totalling more than RM1000 will get 10%% discount\n");
	printf("Orders totalling between RM500 and RM1000 will get 5%% discount\n");
	printf("****************************************************************\n");

	printf("Start Ordering? (y=yes) (n=no) :");
	scanf("%c", &yesorno);
	rewind(stdin);

}
void order()
{
	printf("Order No : %d ", ++orderNo);//orderNo start from 1
	printf("\n   Items\t\t  Quantity Required");

	//ordering love letters cookies
	printf("\nLOVE LETTERS @ RM 25.00 per tin :");
	scanf("%d", &num1);
	rewind(stdin);

	if (num1 < 0.0)//customer entered a negative number
	{
		--orderNo;
		printf("\nError.Pls enter a positive number.\n");
		printf("Press 'Enter' to order again.\n");
		getchar();
		order();
	}

	no1 = num1 * LOVEPRICE;

	printf("     Love Letters Order =\t\t RM%10.2f\n", no1);
	printf("     Order Subtotal     = RM %4.2f\n", no1);

	//ordering nut cookies
	printf("NUT COOKIES  @ RM 20.00 per jar :");
	scanf("%d", &num2);
	rewind(stdin);

	if (num2 < 0.0) //customer entered a negative number
	{
		--orderNo;
		printf("\nError.Pls enter a positive number.\n");
		printf("Press 'Enter' to order again.\n");
		getchar();
		order();
	}

	no2 = num2 * NUTPRICE;
	sub1 = no1 + no2;

	printf("     Nut Cookies Order  =\t\t RM%10.2f\n", no2);
	printf("     Order Subtotal     = RM %4.2f\n", sub1);

	//ordering assorted cookies
	printf("ASST COOKIES @ RM 15.00 per jar :");
	scanf("%d", &num3);
	rewind(stdin);

	if (num3 < 0.0) //customer entered a negative number
	{
		--orderNo;
		printf("\nError.Pls enter a positive number.\n");
		printf("Press 'Enter' to order again.\n");
		getchar();
		order();
	}

	no3 = num3 * ASSORTEDPRICE;
	total = sub1 + no3;

	printf("     Asst Cookies Order =\t\t RM%10.2f\n", no3);

	//display total
	printf("\t\t\t\t\t ------------");
	printf("\n\t\t      ORDER TOTAL    :   RM%10.2f", total);
	printf("\nConfirm / Cancel Order (y = confirm) (c = cancel) :");
	scanf("%s", &yesorno);
	rewind(stdin);

	while (yesorno == 'y' || yesorno == 'Y')
	{
		orderconfirm();
	}
	while (yesorno != 'y' && yesorno != 'Y')
	{
		--orderNo;
		printf("\nOrder Cancelled.");
		printf("\nPress 'Enter' to do next order.\n");
		getchar();
		order();
	}
}
void orderconfirm()
{
	printf("Got member cards? (y=yes) (n=no) :");
	scanf("%c", &yesorno);
	rewind(stdin);
	member();//check member discount

	discount(); //check sales discount
	amountPay = total - discountget - memberdiscount;
	printf("\n\t\t      AMOUNT TO PAY  :   RM%10.2f", amountPay);

	printf("\n\t\t      DEPOSIT        :   RM    ");
	scanf("%f", &deposit);
	rewind(stdin);

	if (deposit < 0.0)//customer entered a negative number	
	{
		printf("\nError.Pls enter a positive number.\n");
		printf("Press 'Enter' to re-enter the number.\n");
		getchar();
		orderconfirm();
	}

	else if (deposit > amountPay)//customer entered deposit more than amount to pay
	{
		printf("\nError.Deposit cannot more than amount to pay.\n");
		printf("Press 'Enter' to re-enter the deposit.\n");
		getchar();
		orderconfirm();
	}

	balance = amountPay - deposit;

	printf("\t\t      BALANCE        :   RM%10.2f", balance);

	//Order Note
	printf("\n===============================================================");
	printf("\nTARUC FESTIVE COOKIES SDN BHD\t\tPhone     :%s", phone);
	printf("\n\tORDER NOTE\t\t\tOrder Date:%d/%d/%d", dd, mm, yy);
	printf("\nYour order No is: %d\t\t\tReady in 4 days.", orderNo);
	printf("\n    %3d LOVE LETTERS @ RM 25.00 per tin :RM%10.2f", num1, no1);
	printf("\n    %3d NUT  COOKIES @ RM 20.00 per jar :RM%10.2f", num2, no2);
	printf("\n    %3d ASST COOKIES @ RM 15.00 per jar :RM%10.2f", num3, no3);
	printf("\n                   ORDER TOTAL        :  RM%10.2f", total);
	printf("\n                   MEMBER DISCOUNT    :  RM%10.2f", memberdiscount);
	printf("\n                   DISCOUNT           :  RM%10.2f", discountget);
	printf("\n                   AMOUNT TO PAY      :  RM%10.2f", amountPay);
	printf("\n                   DEPOSIT PAID       :  RM%10.2f", deposit);
	printf("\n                   BALANCE            :  RM%10.2f", balance);
	printf("\nThank you for your order.");
	printf("\nPlease bring this order note when collecting your cookies. :-)\n");
	printf("===============================================================");

	printf("\nNext Order (y = yes) (n = no) ?");
	scanf("%c", &yesorno);
	rewind(stdin);

	//update order summary values
	tnum1 += num1;
	tnum2 += num2;
	tnum3 += num3;
	tOrderNo += 1;
	tno1 += no1;
	tno2 += no2;
	tno3 += no3;
	tSales += total;
	tMemberDiscount += memberdiscount;
	tDiscount += discountget;
	tNetSales = tSales - tDiscount - tMemberDiscount;
	tDeposit += deposit;
	tBalance += balance;

	nextorder();
}

void discount()
{
	if (total >= 500 && total <= 1000)
	{
		discountget = total * DISCOUNT1;
		printf("\n\t\t      DISCOUNT (5%%)  :   RM%10.2f", discountget);
	}
	else if (total > 1000)
	{
		discountget = total * DISCOUNT2;
		printf("\n\t\t      DISCOUNT (10%%) :   RM%10.2f", discountget);
	}
	else
	{
		discountget = total * 0;
		printf("\n\t\t      DISCOUNT       :   RM%10.2f", discountget);
	}
}

void nextorder()
{


	if (yesorno == 'y' || yesorno == 'Y')
	{
		order();
	}
	else
	{
		//order summary
		printf("\t\t ORDER SUMMARY FOR TODAY (%d/%d/%d)\n", dd, mm, yy);
		printf("\t\t =======================\n");
		printf("Total Number of Customer Orders : %d\n", tOrderNo);
		printf("  Total Orders                Unit Price           Amount\n");
		printf("     %3d LOVE LETTERS    @ RM  25.00 per tin : RM%10.2f\n", tnum1, tno1);
		printf("     %3d NUT  COOKIES    @ RM  20.00 per jar : RM%10.2f\n", tnum2, tno2);
		printf("     %3d ASST COOKIES    @ RM  15.00 per jar : RM%10.2f\n", tnum3, tno3);
		printf("\t\t\t\t\t       ------------\n");
		printf("                      TOTAL SALES            : RM%10.2f\n", tSales);
		printf("                      TOTAL MEMBER DISCOUNTS : RM%10.2f\n", tMemberDiscount);
		printf("                      TOTAL DISCOUNTS        : RM%10.2f\n", tDiscount);
		printf("\t\t\t\t\t       ------------\n");
		printf("                      TOTAL NET SALES        : RM%10.2f\n", tNetSales);
		printf("\t\t\t\t\t       ============\n");
		printf("                      TOTAL DEPOSITS         : RM%10.2f\n", tDeposit);
		printf("                      TOTAL BALANCE          : RM%10.2f\n\n", tBalance);

		system("pause");
	}
}

void member()
{
	if (yesorno == 'y' || yesorno == 'Y')
	{
		memberdiscount = total * MEMBERDISCOUNT;
		printf("\t\t      MEMBER   (15%%) :   RM%10.2f", memberdiscount);
	}
	else
	{
		memberdiscount = total * 0;
		printf("\t\t      MEMBER   (0%%)  :   RM%10.2f", memberdiscount);
	}

}