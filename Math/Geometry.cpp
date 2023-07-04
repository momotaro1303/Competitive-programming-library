//ベクトルの定義
struct Vector2D{
  ld x;
  ld y;
};
//ベクトルの長さを計算する
ld get_vector_length( Vector2D v ) {
  return pow( ( v.x * v.x ) + ( v.y * v.y ), 0.5 );
}
//ベクトル内積
ld dot_product(Vector2D vl, Vector2D vr) {
  return vl.x * vr.x + vl.y * vr.y;
}
//２つのベクトルABのなす角度θ(θ<=180)を求める
ld AngleOf2Vector(Vector2D A, Vector2D B )
{
  //　※ベクトルの長さが0だと答えが出ませんので注意してください。
  //ベクトルAとBの長さを計算する
  ld length_A = get_vector_length(A);
  ld length_B = get_vector_length(B);
  //内積とベクトル長さを使ってcosθを求める
  ld cos_sita = dot_product(A,B) / ( length_A * length_B );
  //cosθからθを求める
  ld sita = acos(cos_sita); 
  //ラジアンでなく0～180の角度でほしい場合はコメント外す
  sita = sita * 180.0/M_PI;
  return sita;
}

//ベクトル(dx,dy)のx軸から反時計回りの角度
long double angle(ld dx,ld dy){
  long double radian=atan2(dy, dx);
  radian=radian*(180.0/M_PI);
  if(radian<0) radian+=360.0;
  return radian;
}

//ベクトル(dx,dy)を反時計回りにsitaだけ回転
// PPをldに　桁指定も
  auto rotate=[&](ld dx,ld dy,ld sita){
    ld Sita=sita*M_PI/180.0;
    ld rotate_dx=dx*cos(Sita)-dy*sin(Sita);
    ld rotate_dy=dy*cos(Sita)+dx*sin(Sita);
    PP ret=PP{rotate_dx,rotate_dy};
    return ret;
  };
  PP VEC=rotate(1,0,90);
  cout << fixed << setprecision(10);

 
