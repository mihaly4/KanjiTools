#include "d3xx.h"
class d302 : public d3xx
{
  public: 
    std::string GetGroupName()
    {
	return "61 to 120";
    }
    d302() 
  { 
   std::string * arrayOfString1 = new std::string[20] { "二", "ニ", "x", "ふた（つ）", "x", "deux", "x", "x", "two", "x", "x", "二月　（にがつ）", "二ヶ月　（にかげつ）", "二回　（にかい）", "février", "deux mois", "deux fois", "February", "two months", "twice" };
    ksdb[0] = arrayOfString1;
   std::string * arrayOfString2 = new std::string[20] { "日", "ニチ", "ジツ", "ひ", "か", "soleil", "jour", "x", "sun", "day", "x", "日曜日（にちようび）", "日本（にほん）", "日仏学院（にちふつがくいん）", "dimanche", "Japon", "Institut Franco-Japonais", "Sunday", "Japan", "Franco-Japanese Institute" };
    ksdb[1] = arrayOfString2;
   std::string * arrayOfString3 = new std::string[20] { "入", "ニュウ", "x", "はい（る）", "い（れる）", "entrer", "mettre dans", "x", "to enter", "to put in", "x", "輸入　（ゆにゅう）", "入り口　（いりぐち）", "加入する（かにゅうする）", "import", "entrée", "devenir membre, joindre", "import", "entrance", "to become a member, to join" };
    ksdb[2] = arrayOfString3;
   std::string * arrayOfString4 = new std::string[20] { "年", "ネン", "x", "とし", "x", "année", "x", "x", "year", "x", "x", "去年（きょねん）", "一年間（いちねんかん）", "年寄り（としより）", "l'année dernière", "un an, une année", "une personne âgée", "last year", "(period of) one year", "old person" };
    ksdb[3] = arrayOfString4;
   std::string * arrayOfString5 = new std::string[20] { "白", "ハク", "x", "しろ（い）", "x", "blanc", "x", "x", "white", "x", "x", "白人（はくじん）", "空白（くうはく）", "真っ白（まっしろ）", "personne de race blanche", "blanc (dans une phrase), vide", "tout blanc", "Caucasian", "blank space, vacuum", "all white" };
    ksdb[4] = arrayOfString5;
   std::string * arrayOfString6 = new std::string[20] { "八", "ハチ", "x", "や", "x", "huit (8)", "x", "x", "eight", "x", "x", "八月（はちがつ）", "八百屋（やおや）", "八日（ようか）", "août", "marchand de primeurs", "le 8 du mois, durée de 8 jours", "August", "greengrocer", "the eighth day of the month, eight days" };
    ksdb[5] = arrayOfString6;
   std::string * arrayOfString7 = new std::string[20] { "百", "ヒャク", "x", "もも", "x", "cent (100)", "x", "x", "hundred (100)", "x", "x", "百貨店（ひゃっかてん）", "三百（さんびゃく）", "百姓（ひゃくしょう）", "grand magasin", "trois cents (300)", "paysan, fermier", "department store", "three hundred (300)", "farmer" };
    ksdb[6] = arrayOfString7;
   std::string * arrayOfString8 = new std::string[20] { "文", "ブン", "モン", "ふみ", "x", "écrit", "texte", "x", "writing", "text", "x", "文字（もじ）", "文学（ぶんがく）", "注文（ちゅうもん）", "lettre, caractère", "littérature", "commande (d'un article, au restaurant, etc.)", "character, letter", "literature", "order, request" };
    ksdb[7] = arrayOfString8;
   std::string * arrayOfString9 = new std::string[20] { "木", "ボク", "モク", "き", "こ", "arbre", "bois", "x", "tree", "wood", "x", "木曜日（もくようび）", "木材（もくざい）", "木炭（もくたん）", "jeudi", "bois  (matériau)", "charbon de bois", "Thursday", "lumber, timber, wood", "charcoal" };
    ksdb[8] = arrayOfString9;
   std::string * arrayOfString10 = new std::string[20] { "本", "ホン", "x", "もと", "x", "origine", "racine", "livre", "origin", "root", "book", "日本（にほん）", "本屋（ほんや）", "基本（きほん）", "le Japon", "librairie", "la base, les fondations", "Japan", "bookstore", "foundation, base" };
    ksdb[9] = arrayOfString10;
   std::string * arrayOfString11 = new std::string[20] { "名", "メイ", "ミョウ", "な", "x", "nom", "renommée", "x", "name", "fame", "x", "有名な（ゆうめいな）", "名前（なまえ）", "匿名の（とくめいの）", "célèbre", "nom", "anonyme", "famous", "name", "anonymous" };
    ksdb[10] = arrayOfString11;
   std::string * arrayOfString12 = new std::string[20] { "目", "モク", "ボク", "め", "ま", "oeil", "suffixe", "ordinal", "eye", "ordinal suffix", "x", "右目（みぎめ）", "注目（ちゅうもく）", "目撃（もくげき）", "l'oeil droit", "(faire) attention", "témoin oculaire", "right eye", "(to pay) attention", "(eye) witness" };
    ksdb[11] = arrayOfString12;
   std::string * arrayOfString13 = new std::string[20] { "立", "リツ", "リュウ", "た（つ）", "た（てる）", "se lever", "ériger", "partir", "to stand", "to rise", "to leave", "立ち入り禁止（たちいりきんし）", "目立つ（めだつ）", "国立（こくりつ）", "          entrée interdite", "être évident", "national (ex. parc national)", "          No Entry! No Trespassing!", "to stand out", "national" };
    ksdb[12] = arrayOfString13;
   std::string * arrayOfString14 = new std::string[20] { "力", "リョク", "リキ", "ちから", "x", "force", "effort", "x", "strength", "effort", "x", "能力（のうりょく）", "力士（りきし）", "努力（どりょく）", "aptitude", "lutteur de sumō", "grand effort", "ability", "sumō wrestler", "great effort, exertion, endeavour" };
    ksdb[13] = arrayOfString14;
   std::string * arrayOfString15 = new std::string[20] { "林", "リン", "x", "はやし", "x", "forêt", "bois", "x", "forest", "woods", "x", "小林（こばやし）", "農林（のうりん）", "竹林（ちくりん）", "Kobayashi (nom de famille)", "agriculture et forêts", "bosquet, forêt de bambous", "Kobayashi (family name)", "agriculture and forestry", "bamboo thicket" };
    ksdb[14] = arrayOfString15;
   std::string * arrayOfString16 = new std::string[20] { "六", "ロク", "x", "む", "x", "six (6)", "x", "x", "six (6)", "x", "x", "六月（ろくがつ）", "六日（むいか）", "六角形（ろっかくけい）", "juin", "le six (du mois)", "hexagone", "June", "the sixth day of the month", "hexagon" };
    ksdb[15] = arrayOfString16;
   std::string * arrayOfString17 = new std::string[20] { "引", "イン", "x", "ひ（く）", "x", "tirer", "x", "x", "to pull", "to draw", "x", "字引（じびき）", "割引（わりびき）", "引っ越し　（ひっこし）", "dictionnaire", "réduction, rabais, discount", "déménager", "dictionary", "discount, reduction, rebate", "moving (changing residence)" };
    ksdb[16] = arrayOfString17;
   std::string * arrayOfString18 = new std::string[20] { "雲", "ウン", "x", "くも", "x", "nuage", "x", "x", "cloud", "x", "x", "雨雲（あまぐも）", "雲隠れする（くもがくれする）", "雲海（うんかい）", "nuage de pluie", "disparaître, se cacher", "mer de nuages", "rain cloud", "to disappear, to hide oneself", "sea of clouds" };
    ksdb[17] = arrayOfString18;
   std::string * arrayOfString19 = new std::string[20] { "遠", "エン", "x", "とお（い）", "x", "distant", "éloigné", "x", "far", "distant", "x", "遠い（とおい）", "遠足（えんそく）", "遠慮する（えんりょする）", "lointain", "excursion, sortie, pique-nique", "hésiter à, s'abstenir de", "far away", "trip, hike, excursion, picnic", "to refrain from, to be reserved" };
    ksdb[18] = arrayOfString19;
   std::string * arrayOfString20 = new std::string[20] { "何", "カ", "x", "なに", "なん", "qu'est-ce que", "quel", "combien", "what", "which", "how many", "何ですか（なんですか）", "何時（なんじ）", "何も（なにも）", "qu'est-ce que c'est ?", "quelle heure ?", "rien", "what is it?", "what time", "nothing" };
    ksdb[19] = arrayOfString20;
   std::string * arrayOfString21 = new std::string[20] { "科", "カ", "x", "しな", "x", "cours", "section", "x", "course", "section", "x", "科学（かがく）", "教科書（きょうかしょ）", "外科医（げかい）", "science", "manuel, livre de classe", "chirurgien", "science", "text book", "surgeon" };
    ksdb[20] = arrayOfString21;
   std::string * arrayOfString22 = new std::string[20] { "夏", "カ", "ゲ", "なつ", "x", "été", "x", "x", "summer", "x", "x", "夏休み（なつやすみ）", "夏至（げし）", "夏時間（なつじかん）", "vacances d'été", "solstice d'été (21 ou 22 juin)", "heure d'été", "summer holidays", "summer solstice (June 21 or 22)", "daylight saving time, summer time" };
    ksdb[21] = arrayOfString22;
   std::string * arrayOfString23 = new std::string[20] { "家", "カ", "ケ", "いえ", "や", "maison", "spécialiste", "x", "house", "specialist", "x", "貸家（かしや）", "作家（さっか）", "写真家（しゃしんか）", "maison à louer", "écrivain", "photographe", "house for rent", "writer", "photographer" };
    ksdb[22] = arrayOfString23;
   std::string * arrayOfString24 = new std::string[20] { "歌", "カ", "x", "うた", "うた（う）", "chant", "chanson", "chanter", "song", "sing", "x", "歌手（かしゅ）", "歌曲（かきょく）", "歌劇（かげき）", "chanteur, chanteuse", "chanson", "opéra", "singer", "song, tune, melody", "opera" };
    ksdb[23] = arrayOfString24;
   std::string * arrayOfString25 = new std::string[20] { "画", "ガ", "カク", "x", "x", "image(s)", "trait", "(d'un kanji)", "image", "stroke", "(of a kanji)", "映画（えいが）", "画面（がめん）", "計画（けいかく）", "film", "écran (ordinateur, télé)", "plan", "film, movie", "screen (computer, television set)", "plan" };
    ksdb[24] = arrayOfString25;
   std::string * arrayOfString26 = new std::string[20] { "回", "カイ", "x", "まわ（る）", "まわ（す）", "tourner (v.i)", "faire tourner", "x", "turn", "rotate", "x", "見回り（みまわり）", "何回（なんかい）", "回復（かいふく）", "ronde, patrouille", "combien de fois ?", "guérison", "patrol, round of inspection", "how many times?", "recovery (from illness)" };
    ksdb[25] = arrayOfString26;
   std::string * arrayOfString27 = new std::string[20] { "会", "カイ", "エ", "あ（う）", "x", "rencontrer", "rencontre", "x", "meet", "x", "x", "会社（かいしゃ）", "会話（かいわ）", "会合（かいごう）", "entreprise", "conversation", "réunion", "company", "conversation", "meeting, assembly" };
    ksdb[26] = arrayOfString27;
   std::string * arrayOfString28 = new std::string[20] { "海", "カイ", "x", "うみ", "x", "mer", "x", "x", "sea", "x", "x", "海岸（かいがん）", "海外（かいがい）", "海賊（かいぞく）", "côte", "à l'étranger", "pirate", "coast, beach", "abroad", "pirate" };
    ksdb[27] = arrayOfString28;
   std::string * arrayOfString29 = new std::string[20] { "絵", "カイ", "エ", "x", "x", "image", "x", "x", "picture", "x", "x", "絵はがき（えはがき）", "絵本（えほん）", "浮世絵（うきよえ）", "carte postale illustrée", "livre d'images", "ukiyoe", "picture postcard", "picture book", "ukiyoe" };
    ksdb[28] = arrayOfString29;
   std::string * arrayOfString30 = new std::string[20] { "貝", "x", "x", "かい", "x", "coquillage", "x", "x", "shellfish", "shell", "x", "貝殻（かいがら）", "二枚貝（にまいがい）", "x", "coquillage, coquille", "bivalve", "x", "seashell", "bivalve", "x" };
    ksdb[29] = arrayOfString30;
   std::string * arrayOfString31 = new std::string[20] { "外", "ガイ", "ゲ", "そと", "ほか", "dehors", "autre", "dé (faire)", "outside", "other", "undo", "外国人（がいこくじん）", "外交（がいこう）", "外務省（がいむしょう）", "étranger", "diplomatie", "Ministère des Affaires étrangères", "foreigner", "diplomacy", "Ministry of Foreign Affairs" };
    ksdb[30] = arrayOfString31;
   std::string * arrayOfString32 = new std::string[20] { "間", "カン", "ケン", "あいだ", "ま", "espace", "brèche", "x", "space", "gap", "x", "時間（じかん）", "間違い（まちがい）", "間もなく（まもなく）", "heure,  le temps", "erreur", "tout de suite", "time, hour", "mistake", "soon, before long" };
    ksdb[31] = arrayOfString32;
   std::string * arrayOfString33 = new std::string[20] { "顔", "ガン", "x", "かお", "x", "visage", "x", "x", "face", "x", "x", "顔をあわせる（かおをあわせる）", "顔面（がんめん）", "横顔（よこがお）", "rencontrer", "visage", "visage vu de profil", "to meet, to face someone", "face", "profile, face seen from the side" };
    ksdb[32] = arrayOfString33;
   std::string * arrayOfString34 = new std::string[20] { "汽", "キ", "x", "x", "x", "vapeur", "x", "x", "steam", "vapor", "x", "汽車（きしゃ）", "x", "x", "train (à vapeur)", "x", "x", "stream train", "x", "x" };
    ksdb[33] = arrayOfString34;
   std::string * arrayOfString35 = new std::string[20] { "記", "キ", "x", "しる（す）", "x", "récit", "chronique", "noter", "account", "chronicle", "to note", "記者（きしゃ）", "記念（きねん）", "記入（きにゅう）", "journaliste, reporter", "commémoration", "remplir (un formulaire)", "journalist", "commemoration", "filling in a form" };
    ksdb[34] = arrayOfString35;
   std::string * arrayOfString36 = new std::string[20] { "帰", "キ", "x", "かえ（る）", "x", "retour", "x", "x", "to return", "x", "x", "帰る（かえる）", "帰国（きこく）", "帰り道（かえりみち）", "revenir, rentrer", "rentrer au pays, revenir dans son pays d'origine", "(sur) le chemin du retour", "to go back home", "to return to one's country", "(on) the way back" };
    ksdb[35] = arrayOfString36;
   std::string * arrayOfString37 = new std::string[20] { "牛", "ギュウ", "x", "うし", "x", "vache", "taureau", "bovin", "bull", "cow", "x", "牛乳（ぎゅうにゅう）", "牛肉（ぎゅうにく）", "水牛（すいぎゅう）", "lait", "boeuf (viande)", "buffle (d'Asie)", "milk", "beef", "water buffalo" };
    ksdb[36] = arrayOfString37;
   std::string * arrayOfString38 = new std::string[20] { "魚", "ギョ", "x", "うお", "さかな", "poisson", "x", "x", "fish", "x", "x", "魚市場（うおいちば）", "養魚（ようぎょ）", "魚屋（さかなや）", "marché au poisson, criée", "pisciculture", "poissonnerie, marchand(e) de poisson", "fish market", "pisciculture, fish breeding", "fish shop, fish dealer, fishmonger" };
    ksdb[37] = arrayOfString38;
   std::string * arrayOfString39 = new std::string[20] { "京", "キョウ", "ケイ", "x", "x", "la capitale", "x", "x", "capital city", "x", "x", "東京（とうきょう）", "京都（きょうと）", "北京（ぺきん）", "Tōkyō", "Kyōto", "Pékin, Beijing", "Tōkyō", "Kyōto", "Beijing (China)" };
    ksdb[38] = arrayOfString39;
   std::string * arrayOfString40 = new std::string[20] { "強", "キョウ", "ゴウ", "つよ（い）", "x", "fort", "puissant", "x", "strong", "powerful", "x", "勉強（べんきょう）", "強さ（つよさ）", "強調（きょうちょう）", "étude(s)", "force", "insistance, mise en valeur, emphase", "studies", "strength, power", "emphasis, stressed point" };
    ksdb[39] = arrayOfString40;
   std::string * arrayOfString41 = new std::string[20] { "教", "キョウ", "x", "おし（える）", "x", "enseigner", "x", "x", "to teach", "x", "x", "教師（きょうし）", "教室（きょうしつ）", "教科書（きょうかしょ）", "professeur, enseignant", "salle de cours, de classe", "manuel scolaire", "teacher", "classroom", "textbook" };
    ksdb[40] = arrayOfString41;
   std::string * arrayOfString42 = new std::string[20] { "玉", "ギョク", "x", "たま", "x", "boule", "balle", "bijou", "ball", "sphere", "jewel", "十円玉（じゅうえんだま）", "玉ねぎ　（たまねぎ）", "珠玉（しゅぎょく）", "pièce de 10 yens", "oignon", "gemme, bijou", "10 yen coin", "onion", "gem, jewel" };
    ksdb[41] = arrayOfString42;
   std::string * arrayOfString43 = new std::string[20] { "近", "キン", "x", "ちか（い）", "x", "proche", "voisin", "x", "near", "x", "x", "近い（ちかい）", "最近（さいきん）", "近代（きんだい）", "proche, près", "récemment", "contemporain, l'époque actuelle", "close by, near", "recently", "present day, the modern period, recent times" };
    ksdb[42] = arrayOfString43;
   std::string * arrayOfString44 = new std::string[20] { "形", "ケイ", "ギョウ", "かた", "かたち", "forme", "x", "x", "shape", "x", "x", "三角形（さんかくけい）", "形容詞（けいようし）", "過去形（かこけい）", "triangle", "adjectif qualificatif", "la / les formes d'un verbe au passé", "triangle", "adjective (grammar)", "the past tense form of a verb" };
    ksdb[43] = arrayOfString44;
   std::string * arrayOfString45 = new std::string[20] { "計", "ケイ", "x", "はか（る）", "x", "mesurer", "x", "x", "measure", "x", "x", "計算する（けいさんする）", "合計（ごうけい）", "計画（けいかく）", "calculer, faire les comptes", "total (résultat d'une somme)", "plan, projet", "to calculate", "total ", "plan, project" };
    ksdb[44] = arrayOfString45;
   std::string * arrayOfString46 = new std::string[20] { "元", "ゲン", "ガン", "もと", "x", "origine", "source", "x", "origin", "source", "x", "元気（げんき）", "元々（もともと）", "復元（ふくげん）", "en bonne santé", "à l'origine, depuis le début", "restauration, remise à l'état d'origine", "good health", "originally, from the start", "restoration (to original state)" };
    ksdb[45] = arrayOfString46;
   std::string * arrayOfString47 = new std::string[20] { "原", "ゲン", "x", "はら", "x", "plaine", "origine", "x", "plain", "origin", "x", "高原（こうげん）", "原稿（げんこう）", "原論（げんろん）", "plateau (sens topographique)", "manuscrit", "théorie, principe", "plateau, mesa", "manuscript, draft", "principle, theory" };
    ksdb[46] = arrayOfString47;
   std::string * arrayOfString48 = new std::string[20] { "戸", "コ", "x", "と", "x", "porte", "x", "x", "door", "x", "x", "戸籍（こせき）", "江戸（えど）", "井戸（いど）", "registre d'état civil", "Edo (ancien nom de Tōkyō)", "puits (eau)", "family register", "Edo (old name of Tōkyō)", "water well" };
    ksdb[47] = arrayOfString48;
   std::string * arrayOfString49 = new std::string[20] { "古", "コ", "x", "ふる（い）", "x", "vieux", "x", "x", "old", "x", "x", "考古学（こうこがく）", "古代エジプト（こだいえじぷと）", "古典的（こてんてき）", "archéologie", "l'Égypte de l'antiquité", "classique", "archaeology", "ancient Egypt", "classical" };
    ksdb[48] = arrayOfString49;
   std::string * arrayOfString50 = new std::string[20] { "午", "ゴ", "x", "x", "x", "midi", "x", "x", "noon", "x", "x", "午前（ごぜん）", "午後（ごご）", "x", "le matin", "l'après-midi", "x", "morning, a.m.", "afternoon, p.m.", "x" };
    ksdb[49] = arrayOfString50;
   std::string * arrayOfString51 = new std::string[20] { "後", "ゴ", "コウ", "うしろ", "あと", "après", "derrière", "x", "behind", "after", "x", "後で（あとで）", "後半（こうはん）", "後述のように（こうじゅつのように）", "plus tard, après", "la seconde moitié", "                  comme décrit ci-dessous", "afterwards", "the second half", "                  as described below" };
    ksdb[50] = arrayOfString51;
   std::string * arrayOfString52 = new std::string[20] { "語", "ゴ", "x", "かた（る）", "x", "dire", "parler", "x", "to tell", "to speak", "to talk", "日本語（にほんご）", "語彙（ごい）", "物語（ものがたり）", "la langue japonaise", "vocabulaire", "épopée, légende, histoire", "the Japanese language", "vocabulary", "tale, story, legend" };
    ksdb[51] = arrayOfString52;
   std::string * arrayOfString53 = new std::string[20] { "工", "コウ", "ク", "x", "x", "travail", "x", "x", "work", "x", "x", "工事（こうじ）", "工場（こうじょう）", "人工（じんこう）", "travaux de construction", "usine", "artificiel", "construction work", "factory, plant", "manmade, artificial" };
    ksdb[52] = arrayOfString53;
   std::string * arrayOfString54 = new std::string[20] { "広", "コウ", "x", "ひろ（い）", "ひろ（げる）", "spacieux", "large", "grand", "spacious", "wide", "x", "広場（ひろば）", "広告（こうこく）", "広島（ひろしま）", "place (comme la Concorde)", "publicité", "Hiroshima", "square (like Times Square)", "advertisement", "Hiroshima" };
    ksdb[53] = arrayOfString54;
   std::string * arrayOfString55 = new std::string[20] { "交", "コウ", "x", "ま（じる）", "か（わす）", "mélanger", "échanger", "x", "to mix", "to exchange", "x", "交換（こうかん）", "交通（こうつう）", "交差点（こうさてん）", "échange, substitution", "circulation", "intersection, carrefour", "exchange, substitution", "traffic (transportation)", "intersection (streets, roads)" };
    ksdb[54] = arrayOfString55;
   std::string * arrayOfString56 = new std::string[20] { "光", "コウ", "x", "ひか（る）", "ひか（り）", "lumière", "briller", "x", "light", "to shine", "x", "光りの速さ（ひかりのはやさ）", "光ファイバー（ひかりファイバー）", "光線（こうせん）", "vitesse de la lumière", "          fibre optique", "rayon lumineux", "speed of light", "          optical fiber", "light beam" };
    ksdb[55] = arrayOfString56;
   std::string * arrayOfString57 = new std::string[20] { "考", "コウ", "x", "かんが（える）", "x", "réfléchir", "penser", "x", "think", "consider", "x", "考案（こうあん）", "考え方（かんがえかた）", "参考（さんこう）", "plan, idée", "façon de penser", "référence", "plan, idea", "way of thinking", "reference" };
    ksdb[56] = arrayOfString57;
   std::string * arrayOfString58 = new std::string[20] { "行", "コウ", "ギョウ", "い（く）", "おこな（う）", "aller", "faire", "ligne", "to go", "to do", "line", "通行止め（つうこうどめ）", "行方不明（ゆくえふめい）", "行為（こうい）", "Circulation interdite, Passage interdit", "porté disparu", "actes, comportement", "No Thoroughfare! Road Blocked!", "missing, unaccounted for", "act, deed, conduct" };
    ksdb[57] = arrayOfString58;
   std::string * arrayOfString59 = new std::string[20] { "高", "コウ", "x", "たか", "たか（い）", "grand", "haut", "somme", "tall", "high", "sum", "高校（こうこう）", "高速道路（こうそくどうろ）", "高品質（こうひんしつ）", "lycée", "autoroute", "qualité supérieure", "senior high school", "freeway, highway", "high quality" };
    ksdb[58] = arrayOfString59;
   std::string * arrayOfString60 = new std::string[20] { "黄", "コウ", "オウ", "き（いろ）", "x", "jaune", "x", "x", "yellow", "x", "x", "黄色（きいろ）", "黄金（おうごん）", "硫黄（いおう）", "jaune", "or", "soufre (S)", "yellow", "gold", "sulfur, sulphur" };
    ksdb[59] = arrayOfString60;
  }
};
