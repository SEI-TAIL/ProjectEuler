#include <iostream>
#include <map>
#include <boost/range.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/if.hpp>
#include <boost/lambda/loops.hpp>
 
int projecteuler021(void) {
        namespace bll = boost::lambda;
        namespace rng = boost::range;
        using namespace boost;
        using std::cout;
        using std::endl;
        using bll::_1;
        using bll::var;
        using bll::constant;
        int i,j;
        int sumAmicable = 0;
        int amicable, sumFactor;
        std::map<int, int> memo;
        for_each(irange(1, 10000), (
                            var(amicable) = 0
                          , var(sumFactor) = 0
                          , bll::if_(var(memo)[bll::_1]!=1)
                            [
                                  bll::for_(var(j)=1, var(j)<=(bll::_1/2), ++var(j))
                                  [
                                    bll::if_(bll::_1 % var(j)==0)
                                        [
                                          var(sumFactor) += var(j)
                                        ]
                                  ],
                                  bll::for_(var(j)=1, var(j)<=(var(sumFactor)/2), ++var(j))
                                  [
                                    bll::if_(var(sumFactor) % var(j)==0)
                                        [
                                          var(amicable) += var(j)
                                        ]
                                  ],
                                  bll::if_(var(amicable)==bll::_1 && var(amicable)!=var(sumFactor))
                                  [
                                     var(sumAmicable) = var(sumAmicable)+var(sumFactor)+var(amicable)
                                        ,var(memo)[var(sumFactor)] = 1
                                        ,var(memo)[var(amicable) ] = 1
                                        ,cout << var(sumFactor) << " " << var(amicable) << "\n"
                                  ].else_[
                                    var(memo)[var(sumFactor)] = 1
                                  ]
                                ]/*.else_[
                                  cout << constant("else:") << bll::_1 << "\n"
                                ]*/
                        ));
        cout << sumAmicable << endl;
        return sumAmicable;
}
 
int main () {
        projecteuler021();
}
 
