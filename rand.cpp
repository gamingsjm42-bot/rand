
//includes
#include  <time.h> 
#include  <random>
#include <map>
//that creaT
 namespace randd

 {
    //that create random number and big
    //@param max that a bigger number that create
    //@param min that create a smaller number that create   
        size_t random(  size_t max =9999999, size_t min=  0 ) 
    {
 
        //error 
        if(min>max){throw max;}
        //returning vars
          long returning= time(nullptr);
        //fix t<max
        while(   returning< max  )
        { 
            returning*=2;
        }
        //returning more rand
        returning  *=rand(); 
        if(returning <0) {returning= -returning;}
        
        //returning in[min,max]
         returning%=(max-min+1); 
         //returning
         return returning;
    }
    //@overload
   // size_t random(size_t max=9999999999,size_t min=0) 
   // {
   //     auto fun =[](size_t x) {return x;};
   //     return random(max,min ,fun);
   // }
    //arra
     //that function call random element from an array
    //@param array that array return on this
    //@param size number of element
     template<typename Arr,typename ele >
     ele randArr (Arr array,size_t size) {return array[random(size-1,0 )];};
        //@param ArrWithPropability that arr create as a {{size_t is propability,element},.....}
     template<typename element>
     element randArr(std::map<element,size_t>   ArrWithPropability )
     { 
        //newLen
        int  allLen=0  ;
         
        //allLEN Set All
        for ( auto i = ArrWithPropability.begin() ; i != ArrWithPropability.end(); i++)
        {
            allLen+=i->second ;
        } 
        //VARS
        size_t rnd = random(allLen );
        size_t vr=0,vrEnd=vr;

        //returning
        for (auto i = ArrWithPropability.begin(); i !=ArrWithPropability.end(); i++)
        { 
            //VR CONFIG  
            vr+=i->second; 
            //RETURNING
             if(rnd >=vrEnd&& rnd  <=vr ){return i->first ;} 
             //VRend conf
            vrEnd =vr; 
        }  
      throw ArrWithPropability;
     }   
     // 
 } // namespace random
 //that function create like n! =1*2*3*....*n
 //@param n that  
    size_t  bar(size_t n){
        size_t returning =1;
         for(size_t i =0;i<(n+1);i++)
         {
            if(i>0)
            {returning*=i;};
        }
        return returning;
    }
    //that function with ranking  and no repetition 
    //@param p that biggen num of list (A,B,..)
    //@param n  that num of objects 
     size_t A(size_t p,size_t n){return bar(n)/bar(n-p);}
    //that function with  repetition and no ranking 
    //@param p that biggen num of list (A,B,..)
    //@param n  that num of objects
     size_t C(size_t p,size_t n){return A(p,n)/bar(p);}
     //propabilityObj
 namespace propabilitySpace
 {
    //that object create
    class object
    {
        //@param n  that num of objects 
        size_t n;
        //public
        public:
        //constRactor
        object(size_t s=0):n(s){  /*complette*/}
        //|| that create a new obj this or b
        //@param o 
        object operator||(object o){object returning;returning.n =n*o.n;return returning;}
        // that Create a new obj this and b
        //@param o
        object operator&&(object o){/*var*/object retrning;/*set returning*/retrning.n= (n+o.n)-(o.n*n);/*error*/if(retrning.n <0){throw n;};return retrning;}
        //that  create object
        object operator>>(object o )
        {/*var */object returning;/*set returning*/ returning.n= operator||(o).n/n;/*error*/ if(returning.n<0 ){throw n;}/*returning*/return returning;} 
    };
    //that object
    class randomiseTrial
    {
        //vars
        object *s; 
        //constractor  
    };
 } // namespace propablity space
 