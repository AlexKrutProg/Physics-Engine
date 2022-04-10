import 'package:my_money_handler/userClasses/UserIdentifier.dart';
import 'package:firebase_auth/firebase_auth.dart';
UserIdentifier? _userFromFirebaseuser(user) {
  return user!=null ? UserIdentifier(uid: user.uid) : null;
}
class AuthService {
  final FirebaseAuth _auth = FirebaseAuth.instance;

  Stream<UserIdentifier?> get user {
    return _auth.authStateChanges().map(_userFromFirebaseuser);
  }
  Future registerWithEmailAndPassword(String email,String password) async {
    try {
      var result = await _auth.createUserWithEmailAndPassword(email: email, password: password);
      User? user = result.user;
      return _userFromFirebaseuser(user);
    } catch (error) {
      return null;
    }
  }
  Future signInWithEmailAndPassword(String email,String password) async {
    var result = await _auth.signInWithEmailAndPassword(email: email,
        password: password);
    User? user = result.user;
    return _userFromFirebaseuser(user);
  }
  Future signOut() async {
    try{
      return await _auth.signOut();
    }catch(e) {
      return null;
    }
  }
}