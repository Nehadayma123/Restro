#include<stdio.h>
#include<string.h>
#include<stdio.h>


struct item{
    char item[20];
    float price;
    int qty;
};
struct order{
    char customer[50];
    char date[50];
    int numofitem;
    struct item itm[50];
};

//generate bill
void (char name[100],char date[50]){
    printf("\n\n");
    printf("\t    Grill & Chill");
    printf("\n\t ---------------------");
     printf("\nDate : %s",date);
     printf("\n Invoice To : %s",name);
     printf("\n");
     printf("\n--------------------------------------------------------------\n");
     printf("Items\t\t");
     printf("quantity\t");  
     printf("Total\t\t");   
     printf("\n");
     printf("\n--------------------------------------------------------------\n"); 
    }

void generatedbillbody(char items[30],int qty,float price){
    printf("%s\t\t",items);
     printf("%d\t\t",qty);
    printf("%.2f\t\t",qty*price);
    printf("\n");

}

void generatingbillfooter(float total){
    printf("\n");
    float dis = 0.1*total;
    float netTotal=total-dis;
    float cgst =0.09*netTotal;
    float grandtotal = netTotal + 2*cgst;
    printf("--------------------------------------------------------------\n"); 
    printf("Sub total \t\t\t%.2f",total);
    printf("\nDiscount @10%s \t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t------------");
    printf("\nNet Total \t\t\t%.2f",netTotal);
     printf("\nCGST @9%s \t\t\t%.2f","%",cgst); 
     printf("\n SGST @9%s \t\t\t%.2f","%",dis); 
     printf("\n--------------------------------------------------------------\n"); 
      printf("Grand Total\t\t\t%.2f",grandtotal);
     printf("\n--------------------------------------------------------------\n");    
    
} 


int main(){
    int opt,n,invoiceFound=0;
    float total;
    char name[50];
    struct order ord;
    char savebill = 'y',countflag="y";
    FILE *fp;
    while(countflag == 'y'){
    float total =0;
    invoiceFound =0;
    printf("\t==================== GRILL AND CHILL RESTRO..==================== ");
    printf("\n\nPlease select your prefered operation:\t"); 
    printf("\n1.Generate the invoice");
    printf("\n2.Search invoice");
     printf("\n3.Exit"); 
    printf("\n\nYour choice:\t"); 
    scanf("%d",&opt);
    fgetc(stdin);

    switch(opt){
        case 1:
        system("clear");
        printf("Enter the name of the customer : \t");
        fgets(ord.customer,50,stdin);
        ord.customer[strlen(ord.customer)-1] = 0;
       // strcpy(ord.date,'_DATE_');
        printf("\nPlease enter the number of items  :\t ");
        scanf("%d",&n);
        ord.numofitem =n;
        for(int i=0;i<n;i++){
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d:\t",i+1);
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            printf("\nPlease enter the quantity :\t");
            scanf("%d",&ord.itm[i].qty);
             printf("\nPlease enter the unit price :\t");
             scanf("%f",&ord.itm[i].price);
             total += ord.itm[i].qty * ord.itm[i].price;  
        }
    }
       generatebillhead(ord.customer,ord.date);
         for(int i=0;i<ord.numofitem;i++){
            generatedbillbody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
         }
        generatingbillfooter(total);
        printf("\nDo you want save invoice(y/n) : \t")
        scanf("%s",&savebill);

        if(savebill == 'y')
        {
            fp=fopen("restuarantbill.dat","a+");
            fwrite(&ord,sizeof struct order,1,fp);
            if(fwrite!=0)
            printf("\nsucessfully saved");
            else   printf("\nError");
            fclose(fp);
        }
        break;
        case 2 :
        printf("\nEnter the name of the customer :\t");
        fgetc(stdin);
        fgets(name,50,stdin);
        name[strlen(name)-1] =0;
        system("clear");
        fp = open("Restrorantbill.dat","r");
        printf("\n **** Invoice of %s ****\n,name");
        while(fread(&order,sizeof(struct orders),1,fp)){
            float tot=0;
            if(!strcmp(order.customer,name)){
            generatebillhead(order.customer,order.date);
            for(int i=0;i<order.numofitem;i++){
                generatebillbody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                tot+=order.itm[i].qty * order.itm[i].price;
            }
            generatebillfooter(tot);
            invoiceFound=1;
            }
        }
        if(!invoiceFound){
            printf("sorry the invoice for %s does not generate",name);

        }
        fclose(fp);
        break;

        case 4:
        printf("\n\t\t Bye bye :)\n\n");
        exit(0);
        break;

        default :
        printf("Sorry invalid option");
        break;
}
        printf("\nDo you want to perform another opertion?(y/n):\t");
        scanf("%s",&countflag);
        }
        printf("\n\n");
        
        return 0;
 }       
    
    