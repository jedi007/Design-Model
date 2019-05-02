# Design Model

#基本所有demo背景资料均来自于《大话设计模式》

01.Simple_factory_model           简单工厂模式
02.strategic_model                策略模式
03.decorator_model                装饰器模式
04.proxy_model                    代理模式
05.factory_method_model           工厂方法模式
06.prototype_model                原型模式
07.template_method_model          模板方法模式
08.facade_model                   外观模式，又叫：门面模式
09.builer_model                   建造者模式
10.Observer_model                 观察者模式
11.abstract_factory_model         抽象工厂模式
12.state_model                    状态模式
13.adapter_model                  适配器模式
14.Memento_model                  备忘录模式
15.composite_model                组合模式
16.iterator_model                 迭代器模式
17.Singleton_model                单例模式
18.bridge_model                   桥接模式
19.command_model                  命令模式
20.chain_of_respomsibility_model  责任链模式
21.mediator_model                 中介者模式

实际案例：
01.Simple_factory_model  简单工厂模式
	javascripty 常见
	
02.strategic_model       策略模式
	排序算法演示项目
	
03.decorator_model       装饰器模式

04.proxy_model           代理模式
	智能指针

05.factory_method_model  工厂方法模式

06.prototype_model       原型模式
	拷贝构造函数
	各种值传递应用场景
	
07.template_method_model 模板方法模式
	抽象类
	baseTableWidget
	https://github.com/jedi007/SuperTimer
	模板类、模板函数
	
08.facade_model          外观模式，又叫：门面模式
	为一组button设置不同组合状态
	
09.builer_model          建造者模式
	PSM项目中CMessageBox的构造
	
10.Observer_model        观察者模式
	QT信号槽的实现（还加以反射模式使得使用更加方便）
	
11.abstract_factory_model 抽象工厂模式
	与简单工厂模式、工厂方法模式与建造者模式的不同：
	1.简单工厂模式：所有产品都在同一个工厂进行生产，增加产品需要修改工厂类，将生产产哪个产品的选择放在工厂中进行选择。
	2.工厂方法模式：不同的产品放在不同的工厂进行生产，增加产品则增加相应的工厂，将生产哪个产品的选择放在了客户端进行（客户端选择工厂）。
	3.抽象工厂模式：面向的是产品族，不同产品族在不同发工厂进行生产，每个工厂生产对应产品族下的多个产品。
					增加产品时需要在多个产品族下分别添加，并且同时修改不同产品族对应的工厂。
					最大优点： 快速切换产品族
	4.建造者模式：  工厂模式针对的是整个产品，直接生产出整个完整产品，重点处理不同产品的生产问题。
							***不同工厂生产出的是不同的类
					建造者模式针对的是复杂产品（不同部件、不同组装顺序），生产出产品后还要完成不同的组装。
						  重点处理的是产品new出来之后，再对他进行一些差异性的初始化操作。
						  例如PSM项目中new 了MessageBox之后再对他进行不同的定制化设置。
						    ***不同建造者 建造出的是同一个类的各个不同不同的状态（或者叫不同的部件组合）
					
12.state_model            状态模式

13.adapter_model          适配器模式

14.Memento_model          备忘录模式

15.composite_model        组合模式

16.iterator_model         迭代器模式	
	个人观点，当有多种不同类型的对象集合，都需要使用排序、查找等遍历、访问操作时，
	使用迭代器模式才有价值，且非常有价值。相当于抽象出了共同的操作交给迭代器处理。
	现在很多框架都直接集成了该模式，不用再自己去实现。例如QT当中的QVector等。
	
17.Singleton_model        单例模式
	分懒汉模式和饿汉模式，如果是多线程中需要考虑线程安全
	如PSM项目中的管理员界面