import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:my_money_handler/userClasses/UserData.dart';

UserData userDataFromQuery(QuerySnapshot querySnapshot) {
  Map dataMap = querySnapshot.docs.first.data() as Map<String, dynamic>;
  return UserData(name: dataMap['name'], lastName: dataMap['lastname']);
}

class UserDataBaseService {
  final String uid;

  UserDataBaseService({required this.uid});

  final CollectionReference UserCollection =
      FirebaseFirestore.instance.collection('users');

  Future CreateUserData() async {
    return await UserCollection.doc(uid).set({
      'name': 'default name',
      'last name': 'default lastname',
    });
  }

  Future UpdateUserData() async {
    return await UserCollection.doc(uid).update({});
  }

  Future get user async {
    QuerySnapshot query = await UserCollection.get();
    return await userDataFromQuery(query);
  }
}
