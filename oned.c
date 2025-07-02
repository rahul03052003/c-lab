#include<stdio.h>
main()
{
    int a[15],n,i,pos,val,ch=0;
    printf("Size:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    while(ch!=4){
        printf("\nMenu\n1.Display\n2.Insertion\n3.Deletion\n4.Exit\nEnter the choice");
        scanf("%d",&ch);
        if(ch==1){
            printf("Elements is array:\n");
            for(i=0i;i<n;i++){
                printf("%d\n",a[i]);
            }
        }
        else if(ch==2){
            printf("Enter the position\n");
            scanf("%d",&pos);
            if(pos>=0 && pos<=0){
                printf("Enter the insert\n");
                scanf("%d",&val);
                i=n;
                while(i>pos){
                    a[i]=a[i-1];
                    i--;
                }
                a[pos]=val;
                n++;
                printf("Inserted successfully!\n");
            }else{
                printf("Invalid choice");
            }
        }
        else if(ch==3){
            printf("Position\n");
            scanf("%d",&pos);
            if(pos>=0 && pos<n){
                i=pos;
                while(i<n-1){
                    a[i]=a[i+1];
                    i++;
                }
                n--;
                printf("Deletion successfully!\n");
            }else{
                printf("Invalid");
            }
        }
        else if(ch==4){
            printf("Invalid");
        }
    }
    printf("Exit");
    return 0;
}
