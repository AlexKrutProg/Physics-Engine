import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
class DataBaseService {

  final String uid;
  DataBaseService({required this.uid});
  final CollectionReference UserCollection = FirebaseFirestore.instance
      .collection('users');

  Future CreateUserData() async {
    return await UserCollection.doc(uid).set({});
  }
  Future UpdateUserData() async {
    return await UserCollection.doc(uid).update({});
  }
  Stream<QuerySnapshot?> get data {
     return UserCollection.snapshots();
  }
}