import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';

class offerDataBaseService {
  final String uid;

  offerDataBaseService({required this.uid});

  final CollectionReference offerCollection =
      FirebaseFirestore.instance.collection('offers');

  Future CreateOfferData(
      String title, String subject, String price, String data) async {
    return await offerCollection.doc(uid).set(
        {'title': title, 'subject': subject, 'price': price, 'data': data});
  }

  Stream<QuerySnapshot?> get data {
    return offerCollection.snapshots();
  }
}
