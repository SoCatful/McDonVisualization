//
// Created by tzhca on 2024/6/1.
//

#ifndef MCDVI_PREDICTCOMPTIME_H
#define MCDVI_PREDICTCOMPTIME_H

#define ToTalFood 41//定义总的食物数量
typedef struct {
    int Need[42]={0};//前41存储食物的需求，第42个存储是否已被完成（只要分配了时间就是完成了
    int Time;//预测的完成时间，以秒为单位
}Order;



void PredictCompTime(Order * AllOrders,int orderNum,int *FoodStored,int TIME,int *FoodMakingTime);
//                       订单数组         截至此刻目前的总订单数 食物存量    当前时间
void PredictCompTime(Order * AllOrders,int orderNum,int *FoodStored,int TIME,int *FoodMakingTime){
    int tmp = 0;//暂存目前的最大完成所需时间
    for(int i = 0; i < ToTalFood ; i++ ){
        if(AllOrders[orderNum].Need[i] != 0){//处理的仅有一个订单
            if(FoodStored[i] >= AllOrders[orderNum].Need[i]){
            }else{
                if(tmp < FoodMakingTime[i]*(AllOrders[orderNum].Need[i]-FoodStored[i])){
                    tmp = FoodMakingTime[i]*(AllOrders[orderNum].Need[i]-FoodStored[i]);
                }
            }
            FoodStored[i] -= AllOrders[i].Need[i];

        }
    }
    AllOrders[orderNum].Time = TIME + tmp;
    return;
}
#endif //MCDVI_PREDICTCOMPTIME_H
