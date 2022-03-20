import 'package:firebase_auth/firebase_auth.dart';

import 'Freelancer.dart';
import 'Customer.dart';
import 'package:my_money_handler/subjectsEnum.dart';
import 'package:my_money_handler/services/userDataBase.dart';
class UserData with Freelancer,Customer{
    String name;
    String lastName;
    // List<subject>? skills;
    UserData({required this.name,required this.lastName});
}