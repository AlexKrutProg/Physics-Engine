// ignore_for_file: prefer_const_constructors, prefer_const_literals_to_create_immutables
import 'package:my_money_handler/services/auth.dart';
import 'package:flutter/material.dart';

class SignInPage extends StatefulWidget {
  const SignInPage({Key? key}) : super(key: key);

  @override
  _SignInPageState createState() => _SignInPageState();
}

class _SignInPageState extends State<SignInPage> {
  final AuthService _auth = AuthService();
  final _emailController = TextEditingController();
  final _passwordController = TextEditingController();
  String? error;
  bool _isPasswordInvisible = true;
  final _key = GlobalKey<FormState>();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        margin: EdgeInsets.fromLTRB(40, 10, 40, 0),
        width: 300,
        child: Column(
          children: [
            SizedBox(height: 20),
            Image(image: AssetImage('assets/logo.png')),
            SizedBox(height: 25),
            Form(
              key: _key,
              child: Column(
                children: [
                  TextFormField(
                    validator: (val) => _emailController.text.isEmpty ?
                    'enter email' : null,
                    controller: _emailController,
                    decoration: InputDecoration(
                      labelText: 'email',
                      filled: true,
                      prefixIcon: Icon(Icons.email,
                          color: Theme.of(context).primaryColor),
                      border: InputBorder.none,
                    ),
                  ),
                  SizedBox(
                    height: 10,
                  ),
                  TextFormField(
                    validator: (val) {
                      if (error!=null)
                        return error;
                      return _passwordController.text.length<6 ? 'password must contain at least 6 symbols'
                          : null;
                    } ,
                    controller: _passwordController,
                    obscureText: _isPasswordInvisible,
                    decoration: InputDecoration(
                      labelText: 'password',
                      suffixIcon: IconButton(
                        icon: Icon(_isPasswordInvisible
                            ? Icons.visibility_off
                            : Icons.visibility),
                        color: Theme.of(context).primaryColor,
                        onPressed: () {
                          setState(
                            () {
                              _isPasswordInvisible = !_isPasswordInvisible;
                            },
                          );
                        },
                      ),
                      prefixIcon: Icon(Icons.lock_outline_rounded,
                          color: Theme.of(context).primaryColor),
                      filled: true,
                      border: InputBorder.none,
                    ),
                  ),
                ],
              ),
            ),
            ButtonBar(
              children: [
                TextButton(
                  onPressed: () {
                    Navigator.pushNamed(context, '/signUp');
                  },
                  child: Text(
                    'Sign Up',
                    style: TextStyle(color: Theme.of(context).primaryColor),
                  ),
                ),
                ElevatedButton(
                  style: ButtonStyle(
                    backgroundColor: MaterialStateProperty.all(
                        Theme.of(context).primaryColor),
                  ),
                  onPressed: () async {
                      if (_key.currentState!.validate()) {
                       try{
                         await _auth.signInWithEmailAndPassword(_emailController.text
                             , _passwordController.text);
                       }catch(e) {
                         setState(() {
                           error='wrong email or password';
                         });
                       }
                      }
                  },
                  child: Text('submit'),
                )
              ],
            )
          ],
        ),
      ),
    );
  }
}
