#include "d3xx.h"
 
class d303 : public d3xx
{
  public: 
    std::string GetGroupName()
    {
	return "121 to 180";
    }
    d303() 
    { 
      std::string * arrayOfString1 = new std::string[20] { "合", "ゴウ", "ガﾂ", "あ（う）", "あ（わせる）", "convenir", "joindre", "correspondre", "to fit", "to join together", "to match", "合意（ごうい）", "合計（ごうけい）", "合併（がっぺい）", "accord", "total (d'une somme)", "fusion (sociétés), réunion, combinaison", "agreement, consent", "sum total", "merger, fusion, consolidation" };
    ksdb[0] = arrayOfString1;
    std::string * arrayOfString2 = new std::string[20] { "谷", "コク", "x", "たに", "や", "vallée", "gorge", "x", "valley", "gorge", "x", "谷（たに）", "谷底（たにぞこ、たにそこ）", "x", "vallée", "fond d'une vallée", "x", "valley", "bottom of a valley", "x" };
    ksdb[1] = arrayOfString2;
    std::string * arrayOfString3 = new std::string[20] { "国", "コク", "x", "くに", "x", "pays", "région", "x", "country", "region", "x", "外国人（がいこくじん）", "国境（こっきょう）", "国際（こくさい）", "étranger", "frontière", "international", "foreigner", "border", "international" };
    ksdb[2] = arrayOfString3;
    std::string * arrayOfString4 = new std::string[20] { "黒", "コク", "x", "くろ（い）", "x", "noir", "x", "x", "black", "x", "x", "黒帯（くろおび）", "黒字（くろじ）", "黒人（こくじん）", "ceinture noire (judo, karaté, etc.)", "bilan financier positif", "un Noir", "black belt (judo, karate, etc.)", "balance (figure) in the black", "a black person" };
    ksdb[3] = arrayOfString4;
    std::string * arrayOfString5 = new std::string[20] { "今", "コン", "キン", "いま", "x", "maintenant", "x", "x", "now", "x", "x", "今週（こんしゅう）", "今日は（こんにちは）", "今日（きょう）", "cette semaine", "Bonjour !", "aujourd'hui", "this week", "hello, hi", "today" };
    ksdb[4] = arrayOfString5;
    std::string * arrayOfString6 = new std::string[20] { "才", "サイ", "x", "x", "x", "talent", "x", "x", "talent", "x", "x", "天才（てんさい）", "才力（さいりょく）", "多才（たさい）", "génie, prodige", "talent, aptitude", "talentueux, talentueuse", "genius, prodigy, natural gift", "talent, ability", "talented" };
    ksdb[5] = arrayOfString6;
    std::string * arrayOfString7 = new std::string[20] { "作", "サク", "サ", "つく（る）", "x", "faire", "fabriquer", "oeuvre", "to make", "a work", "a harvest", "作品（さくひん）", "製作（せいさく）", "手作り（てづくり）", "oeuvre", "production", "fait main, fait de façon artisanale", "a work (e.g. a work of art)", "production", "handmade, hand-crafted, homegrown" };
    ksdb[6] = arrayOfString7;
    std::string * arrayOfString8 = new std::string[20] { "算", "サン", "x", "x", "x", "compter", "calculer", "x", "to calculate", "to count", "x", "計算機（けいさんき）", "予算（よさん）", "算数（さんすう）", "calculatrice", "budget prévisionnel, estimation", "arithmétique", "calculator", "estimate, budget", "arithmetics" };
    ksdb[7] = arrayOfString8;
    std::string * arrayOfString9 = new std::string[20] { "止", "シ", "x", "と（める）", "と（まる）", "arrêt", "arrêter (v.t.)", "s'arrêter", "to stop", "x", "x", "中止（ちゅうし）", "禁止（きんし）", "行き止まり（いきどまり、ゆきどまり）", "arrêt, suspension, interruption", "prohibition, interdiction", "                        impasse, cul-de-sac", "suspension, stoppage, interruption", "prohibition, ban", "                        dead-end street, blind alley" };
    ksdb[8] = arrayOfString9;
    std::string * arrayOfString10 = new std::string[20] { "市", "シ", "x", "いち", "x", "ville", "marché", "x", "city", "market", "x", "市場（しじょう）", "魚市場（うおいちば）", "市立（しりつ）", "marché", "marché au poisson", "municipal", "market", "fish market", "municipal" };
    ksdb[9] = arrayOfString10;
    std::string * arrayOfString11 = new std::string[20] { "思", "シ", "x", "おも（う）", "x", "penser", "x", "x", "to think", "x", "x", "思い出（おもいで）", "思想（しそう）", "不思議（ふしぎ）", "souvenirs, réminiscence", "pensée, idée", "curiosité, merveille, étrangeté", "memories, recollections, reminiscence", "thought, idea", "wonder, marvel, curiosity, mystery" };
    ksdb[10] = arrayOfString11;
    std::string * arrayOfString12 = new std::string[20] { "紙", "シ", "x", "かみ", "x", "papier", "x", "x", "paper", "x", "x", "手紙（てがみ）", "和紙（わし）", "画用紙（がようし）", "lettre (correspondance)", "papier japonais traditionnel", "papier à dessin", "letter (correspondence)", "traditional Japanese paper", "drawing paper" };
    ksdb[11] = arrayOfString12;
    std::string * arrayOfString13 = new std::string[20] { "寺", "ジ", "x", "てら", "x", "temple", "(bouddhique)", "x", "temple", "(buddhist)", "x", "お寺（おてら）", "金閣寺（きんかくじ）", "山寺（やまでら）", "un temple bouddhique", "le temple Kinkakuji", "temple de montagne", "temple", "Kinkakuji temple", "mountain temple" };
    ksdb[12] = arrayOfString13;
    std::string * arrayOfString14 = new std::string[20] { "自", "ジ", "シ", "みずから", "x", "soi-même", "x", "x", "self", "oneself", "x", "自然（しぜん）", "自動車（じどうしゃ）", "自由（じゆう）", "la nature", "automobile", "liberté", "nature", "car, automobile", "freedom, liberty" };
    ksdb[13] = arrayOfString14;
    std::string * arrayOfString15 = new std::string[20] { "時", "ジ", "x", "とき", "x", "temps", "heure", "x", "time", "hour", "x", "時間（じかん）", "時々（ときどき）", "一時（いちじ）", "temps ", "de temps en temps", "(il est ) une heure", "time", "sometimes", "one o'clock" };
    ksdb[14] = arrayOfString15;
    std::string * arrayOfString16 = new std::string[20] { "室", "シツ", "x", "むろ", "x", "salle", "pièce", "maison", "room", "house", "x", "教室（きょうしつ）", "室内（しつない）", "地下室（ちかしつ）", "salle de cours, de classe", "à l'intérieur", "sous-sol, cave", "classroom", "indoors", "cellar, basement" };
    ksdb[15] = arrayOfString16;
    std::string * arrayOfString17 = new std::string[20] { "社", "シャ", "x", "やしろ", "x", "sanctuaire", "x", "x", "shrine", "x", "x", "会社（かいしゃ）", "社会（しゃかい）", "神社（じんじゃ）", "compagnie, entreprise", "société (au sens social)", "sanctuaire shintō", "company, enterprise", "society", "shintō shrine" };
    ksdb[16] = arrayOfString17;
    std::string * arrayOfString18 = new std::string[20] { "弱", "ジャク", "x", "よわ（い）", "x", "faible", "faiblesse", "x", "weak", "weakness", "x", "弱点（じゃくてん）", "弱虫（よわむし）", "x", "point faible", "un faible, un poltron", "x", "weak point", "a coward, a weakling", "x" };
    ksdb[17] = arrayOfString18;
    std::string * arrayOfString19 = new std::string[20] { "首", "シュ", "x", "くび", "x", "tête", "cou", "chef", "head", "neck", "chief", "首相（しゅしょう）", "首になる（くびになる）", "首輪（くびわ）", "Premier ministre", "être licencié", "collier (pour animal)", "Prime Minister", "to be fired", "collar (for an animal)" };
    ksdb[18] = arrayOfString19;
    std::string * arrayOfString20 = new std::string[20] { "秋", "シュウ", "x", "あき", "x", "automne", "x", "x", "autumn", "x", "x", "秋田（あきた）", "秋晴れ（あきばれ）", "秋分（しゅうぶん）", "Akita (nom de ville)", "beau temps automnal", "équinoxe d'automne", "Akita (city name)", "clear Autumnal weather", "autumn equinox" };
    ksdb[19] = arrayOfString20;
    std::string * arrayOfString21 = new std::string[20] { "春", "シュン", "x", "はる", "x", "printemps", "x", "x", "spring", "x", "x", "売春（ばいしゅん）", "春巻き（はるまき）", "青春（せいしゅん）", "prostitution", "rouleau de printemps", "un jeune, la jeunesse", "prostitution", "spring roll", "a youth, youth" };
    ksdb[20] = arrayOfString21;
    std::string * arrayOfString22 = new std::string[20] { "書", "ショ", "x", "か（く）", "x", "écrire", "x", "x", "to write", "x", "x", "教科書（きょうかしょ）", "葉書（はがき）", "書類（しょるい）", "livre de cours, de classe", "carte postale", "documents, formulaires", "textbook, schoolbook", "postcard", "documents, official papers" };
    ksdb[21] = arrayOfString22;
    std::string * arrayOfString23 = new std::string[20] { "少", "ショウ", "x", "すこ（し）", "すく（ない）", "un peu de", "peu", "x", "small quantity", "few", "x", "少々（しょうしょう）", "減少（げんしょう）", "少女（しょうじょ）", "quelques instants, un peu", "déclin, baisse, réduction", "fillette, petite fille", "just a minute, small quantity", "decrease, reduction, decline", "little girl, young girl" };
    ksdb[22] = arrayOfString23;
    std::string * arrayOfString24 = new std::string[20] { "場", "ジョウ", "x", "ば", "x", "place", "lieu", "x", "place", "x", "x", "広場（ひろば）", "場所（ばしょ）", "場合（ばあい）", "place (des Vosges par ex.)", "lieu, endroit, emplacement", "cas,  situation", "square (like the Red Square)", "place, location", "case, situation" };
    ksdb[23] = arrayOfString24;
    std::string * arrayOfString25 = new std::string[20] { "色", "ショク", "シキ", "いろ", "x", "couleur", "x", "x", "color", "x", "x", "色々（いろいろ）", "黄色（きいろ）", "無色（むしょく）", "divers", "jaune", "incolore", "various", "yellow", "colourless, achromatic" };
    ksdb[24] = arrayOfString25;
    std::string * arrayOfString26 = new std::string[20] { "食", "ショク", "x", "た（べる）", "く（う）", "manger", "nourriture", "x", "food", "eat", "x", "食べ物（たべもの）", "食事（しょくじ）", "食欲（しょくよく）", "aliment", "repas", "appétit", "food", "meal", "appetite" };
    ksdb[25] = arrayOfString26;
    std::string * arrayOfString27 = new std::string[20] { "心", "シン", "x", "こころ", "x", "coeur", "sentiment", "x", "heart", "feelings", "x", "心臓（しんぞう）", "中心（ちゅうしん）", "心配（しんぱい）", "coeur (l'organe)", "centre", "inquiétude, souci", "heart (organ)", "center, core", "worry, concern" };
    ksdb[26] = arrayOfString27;
    std::string * arrayOfString28 = new std::string[20] { "新", "シン", "x", "あたら（しい）", "あら（た）", "nouveau", "x", "x", "new", "x", "x", "新聞（しんぶん）", "新年（しんねん）", "新たな（あらたな）", "journal", "Nouvel An, année nouvelle", "nouveau", "newspaper", "New Year", "new, novel, fresh" };
    ksdb[27] = arrayOfString28;
    std::string * arrayOfString29 = new std::string[20] { "親", "シン", "x", "おや", "した（しい）", "parent", "intime", "proche", "parent", "intimate", "x", "親類（しんるい）", "両親（りょうしん）", "親切（しんせつ）", "parents (sens large)", "parents (père et mère)", "gentillesse", "relatives", "both parents", "kindness, gentleness" };
    ksdb[28] = arrayOfString29;
    std::string * arrayOfString30 = new std::string[20] { "図", "ズ", "ト", "はか（る）", "x", "plan", "carte", "diagramme", "plan", "diagram", "x", "地図（ちず）", "図書館（としょかん）", "系図（けいず）", "plan, carte", "bibliothèque", "arbre généalogique", "map", "library", "family tree, genealogy" };
    ksdb[29] = arrayOfString30;
    std::string * arrayOfString31 = new std::string[20] { "数", "スウ", "ス", "かず", "x", "nombre", "chiffre", "x", "number", "figure", "x", "数学（すうがく）", "数ヶ月（すうかげつ）", "数字（すうじ）", "mathématiques", "plusieurs mois", "chiffre", "mathematics, arithmetic", "several months", "figure, numeral" };
    ksdb[30] = arrayOfString31;
    std::string * arrayOfString32 = new std::string[20] { "西", "セイ", "サイ", "にし", "x", "ouest", "x", "x", "west", "x", "x", "西洋（せいよう）", "西海岸（にしかいがん）", "西部（せいぶ）", "l'Occident", "la côte ouest", "l'Ouest", "Western countries, the West", "the west coast", "the west part (of a country)" };
    ksdb[31] = arrayOfString32;
    std::string * arrayOfString33 = new std::string[20] { "声", "セイ", "x", "こえ", "x", "voix", "x", "x", "voice", "x", "x", "声をかける（こえをかける）", "声明（せいめい）", "声楽（せいがく）", "adresser la parole à quelqu'un", "déclaration, proclamation", "le chant", "to call out to someone", "declaration, proclamation", "vocal music" };
    ksdb[32] = arrayOfString33;
    std::string * arrayOfString34 = new std::string[20] { "星", "セイ", "ショウ", "ほし", "x", "étoile", "x", "x", "star", "x", "x", "流れ星（ながれぼし）", "火星（かせい）", "衛星（えいせい）", "étoile filante", "Mars", "satellite", "shooting star", "Mars", "satellite" };
    ksdb[33] = arrayOfString34;
    std::string * arrayOfString35 = new std::string[20] { "晴", "セイ", "x", "は（れる）", "x", "clair ", "lumineux", "x", "clear", "bright", "x", "晴れる（はれる）", "晴れ着（はれぎ）", "素晴らしい（すばらしい）", "faire beau, s'éclaircir (temps) ", "(ses) plus beaux vêtements", "magnifique, splendide, super", "to be sunny, to clear away, to stop raining", "one's best clothes", "wonderful, splendid, magnificent" };
    ksdb[34] = arrayOfString35;
    std::string * arrayOfString36 = new std::string[20] { "切", "セツ", "サイ", "き（る）", "x", "couper", "x", "x", "to cut", "x", "x", "切符（きっぷ）", "切れる（きれる）", "親切（しんせつ）", "ticket, billet", "être coupant, affûté", "gentillesse", "ticket", "to be sharp, to cut well", "kindness, gentleness" };
    ksdb[35] = arrayOfString36;
    std::string * arrayOfString37 = new std::string[20] { "雪", "セツ", "x", "ゆき", "x", "neige", "x", "x", "snow", "x", "x", "大雪（おおゆき）", "除雪（じょせつ）", "雪だるま（ゆきだるま）", "forte chute de neige", "déneigement", "bonhomme de neige", "heavy snowfall", "snow removal", "snowman" };
    ksdb[36] = arrayOfString37;
    std::string * arrayOfString38 = new std::string[20] { "船", "セン", "x", "ふね", "x", "bateau", "x", "x", "boat", "ship", "x", "船便（ふなびん）", "船長（せんちょう）", "造船（ぞうせん）", "par bateau (courrier)", "capitaine", "construction navale", "surface mail", "captain", "shipbuilding" };
    ksdb[37] = arrayOfString38;
    std::string * arrayOfString39 = new std::string[20] { "前", "ゼン", "x", "まえ", "x", "avant", "devant", "x", "before", "front", "x", "午前（ごぜん）", "前半（ぜんはん、ぜんぱん）", "前もって（まえもって）", "matin", "première moitié", "à l'avance", "morning", "first half", "beforehand, in advance" };
    ksdb[38] = arrayOfString39;
    std::string * arrayOfString40 = new std::string[20] { "組", "ソ", "x", "くみ", "く（む）", "groupe", "classe", "ensemble", "group", "class", "set", "組み合わせる（くみあわせる）", "組合（くみあい）", "組織（そしき）", "assembler, combiner", "syndicat, association", "organisation", "to join together, to combine", "union, association", "organization" };
    ksdb[39] = arrayOfString40;
    std::string * arrayOfString41 = new std::string[20] { "走", "ソウ", "x", "はし（る）", "x", "courir", "x", "x", "to run", "x", "x", "競走（きょうそう）", "走る（はしる）", "滑走路（かっそうろ）", "course", "courir", "piste (aéroport, aérodrome)", "race", "to run", "runway" };
    ksdb[40] = arrayOfString41;
    std::string * arrayOfString42 = new std::string[20] { "草", "ソウ", "x", "くさ", "x", "herbe", "plante", "x", "grass", "plant", "x", "草原（そうげん）", "草食（そうしょく）", "x", "prairie, savane", "herbivore", "x", "prairie, savannah", "herbivorous", "x" };
    ksdb[41] = arrayOfString42;
    std::string * arrayOfString43 = new std::string[20] { "多", "タ", "x", "おお（い）", "x", "nombreux", "x", "x", "many", "x", "x", "多すぎる（おおすぎる）", "多才（たさい）", "多分（たぶん）", "trop, en excès", "talentueux, doué", "peut-être", "too much", "talented, versatility", "perhaps, probably" };
    ksdb[42] = arrayOfString43;
    std::string * arrayOfString44 = new std::string[20] { "太", "タイ", "タ", "ふと（い）", "ふと（る）", "gros", "gras", "x", "fat", "big", "x", "太陽（たいよう）", "太平洋（たいへいよう）", "太った（ふとった）", "le soleil", "l'Océan Pacifique", "gras, gros, grassouillet", "sun", "Pacific Ocean", "fat, plump, chubby" };
    ksdb[43] = arrayOfString44;
    std::string * arrayOfString45 = new std::string[20] { "体", "タイ", "テイ", "からだ", "x", "corps", "x", "x", "body", "x", "x", "体温（たいおん）", "体操（たいそう）", "体験（たいけん）", "température du corps", "gymnastique", "expérience personnelle", "body temperature", "gymnastics, calisthenics", "personal experience" };
    ksdb[44] = arrayOfString45;
    std::string * arrayOfString46 = new std::string[20] { "台", "ダイ", "タイ", "x", "x", "piédestal", "plate-forme", "x", "stand", "platform", "x", "台風（たいふう）", "台所（だいどころ）", "台湾（たいわん）", "typhon", "cuisine (la pièce)", "Taïwan", "typhoon", "kitchen", "Taiwan" };
    ksdb[45] = arrayOfString46;
    std::string * arrayOfString47 = new std::string[20] { "地", "チ", "ジ", "x", "x", "sol", "terre", "terrain", "ground", "land", "x", "地下（ちか）", "地方（ちほう）", "土地（とち）", "sous-sol", "région", "terrain", "underground", "region", "plot of land" };
    ksdb[46] = arrayOfString47;
    std::string * arrayOfString48 = new std::string[20] { "池", "チ", "x", "いけ", "x", "étang", "bassin", "lac", "pond", "lake", "x", "池袋（いけぶくろ）", "乾電池（かんでんち）", "貯水池（ちょすいち）", "Ikebukuro (un quartier de Tōkyō)", "pile électrique", "lac de rétention, de réserve", "Ikebukuro (a district of Tōkyō)", "dry cell, battery", "reservoir" };
    ksdb[47] = arrayOfString48;
    std::string * arrayOfString49 = new std::string[20] { "知", "チ", "x", "し（る）", "x", "savoir", "connaître", "x", "know", "x", "x", "知り合い（しりあい）", "知識（ちしき）", "知らない（しらない）", "une connaissance (personne)", "la connaissance, le savoir", "inconnu, qu'on ne connaît pas", "acquaintance", "knowledge", "unknown, strange" };
    ksdb[48] = arrayOfString49;
    std::string * arrayOfString50 = new std::string[20] { "竹", "チク", "x", "たけ", "x", "bambou", "x", "x", "bamboo", "x", "x", "竹田（たけだ）", "竿竹（さおだけ）", "竹の子（たけのこ）", "Takeda (patronyme)", "bambou à linge (fil à linge)", "pousse de bambou", "Takeda (family name)", "bamboo pole (for the laundry)", "bamboo shoot" };
    ksdb[49] = arrayOfString50;
    std::string * arrayOfString51 = new std::string[20] { "茶", "チャ", "サ", "x", "x", "thé", "x", "x", "tea", "x", "x", "紅茶（こうちゃ）", "喫茶店（きっさてん）", "茶道（ちゃどう）（さどう）", "thé noir", "café (établissement)", "cérémonie du thé", "black tea", "coffee shop", "tea ceremony" };
    ksdb[50] = arrayOfString51;
    std::string * arrayOfString52 = new std::string[20] { "昼", "チュウ", "x", "ひる", "x", "midi", "journée", "x", "noon", "daytime", "x", "昼間（ひるま）", "昼食（ちゅうしょく）", "昼寝（ひるね）", "(dans) la journée, en plein jour", "repas de midi, déjeuner", "sieste", "daytime, during the day", "midday meal, lunch", "siesta, nap" };
    ksdb[51] = arrayOfString52;
    std::string * arrayOfString53 = new std::string[20] { "長", "チョウ", "x", "なが（い）", "x", "long", "chef", "x", "long", "chief", "x", "成長（せいちょう）", "社長（しゃちょう）", "長過ぎる（ながすぎる）", "croissance", "président d'une compagnie", "(être) trop long", "growth", "company president", "(to be) too long" };
    ksdb[52] = arrayOfString53;
    std::string * arrayOfString54 = new std::string[20] { "鳥", "チョウ", "x", "とり", "x", "oiseau", "x", "x", "bird", "x", "x", "焼き鳥（やきとり）", "白鳥（はくちょう）", "七面鳥（しちめんちょう）", "poulet grillé (en brochette)", "cygne", "dinde", "grilled chicken (on a skewer)", "swan", "turkey" };
    ksdb[53] = arrayOfString54;
    std::string * arrayOfString55 = new std::string[20] { "朝", "チョウ", "x", "あさ", "x", "matin", "x", "x", "morning", "x", "x", "早朝（そうちょう）", "朝ご飯（あさごはん）", "朝鮮（ちょうせん）", "tôt le matin", "petit déjeuner", "Corée", "early morning", "breakfast", "Korea" };
    ksdb[54] = arrayOfString55;
    std::string * arrayOfString56 = new std::string[20] { "通", "ツウ", "x", "とお（る）", "かよ（う）", "passer", "x", "x", "to pass by", "x", "x", "大通り（おおどおり）", "通信（つうしん）", "一通のメッセージ（いっつう）", "grand' rue, avenue", "communication, correspondance", "un message (un e-mail par exemple)", "main street", "communication, correspondence", "one message (one e-mail for example)" };
    ksdb[55] = arrayOfString56;
    std::string * arrayOfString57 = new std::string[20] { "弟", "テイ", "ダイ", "おとうと", "x", "jeune frère", "x", "x", "younger brother", "x", "x", "兄弟（きょうだい）", "弟子（でし）", "x", "(des) frères", "élève, disciple", "x", "brothers, siblings", "pupil, disciple", "x" };
    ksdb[56] = arrayOfString57;
    std::string * arrayOfString58 = new std::string[20] { "店", "テン", "x", "みせ", "x", "magasin", "x", "x", "store", "x", "x", "本店（ほんてん）", "店員（てんいん）", "百貨店（ひゃっかてん）", "magasin principal, maison mère", "vendeur, vendeuse", "grand magasin", "main store", "salesperson, clerk", "department store" };
    ksdb[57] = arrayOfString58;
    std::string * arrayOfString59 = new std::string[20] { "点", "テン", "x", "x", "x", "point", "marque", "x", "point", "mark", "dot", "句点（くてん）", "得点（とくてん）", "氷点下（ひょうてんか）", "point (ponctuation)", "score, points obtenus", "en dessous de zéro (température)", "period, full stop", "score, marks", "below freezing" };
    ksdb[58] = arrayOfString59;
    std::string * arrayOfString60 = new std::string[20] { "電", "デン", "x", "x", "x", "électricité", "x", "x", "electricity", "x", "x", "電気（でんき）", "電話（でんわ）", "乾電池（かんでんち）", "électricité", "téléphone", "pile électrique", "electricity", "telephone", "dry battery" };
    ksdb[59] = arrayOfString60;
  }
};