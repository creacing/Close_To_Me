import avator from './../public/images/avator.jpg'
const author = 'Cheshire Cat'
const config = {
    author,
    CNName: '柴郡猫',
    description: 'Wonderland',
    nav: [
        { name: author, link: "/", children: [], liClass: 'title', rel: 'start', iClass: '', aClass: '' },
        { name: '首页', link: "/", children: [], liClass: '', rel: 'section', iClass: 'i-feather', aClass: '' },
        { name: '归档', link: "/archive", children: [], liClass: '', rel: 'section', iClass: 'i-list-alt', aClass: '' },
        { name: '标签', link: "/tag", children: [], liClass: '', rel: 'section', iClass: 'i-tag', aClass: '' },
        { name: '收藏', link: "/site", children: [], liClass: '', rel: 'section', iClass: 'i-star', aClass: '' },
        { name: '关于', link: "/about", children: [], liClass: '', rel: 'section', iClass: 'i-cloud', aClass: '' },
        { name: 'Github', link: "#", children: [], liClass: '', rel: 'noopener external nofollow noreferrer', iClass: 'i-paper-plane', aClass: '' }
    ],
    sidebar: {
        avator,
        author,
        description: '一个专注于前端的web爱好者',
        articlesNum: '0',
        categoriesNum: '0',
        tagsNum: '33',
        socialLinks: [
            { url: 'https://github.com/creacing/Close_To_Me', name: 'github', icon: "i-github" },
        ],
        localPath: [
            { url: '/', icon: 'i-feather', name: 'could1', },
            { url: '/archive', icon: 'i-list-alt', name: 'could2', },
            { url: '/tag', icon: 'i-tag', name: 'could3', },
            { url: '/site', icon: 'i-star', name: 'could4', },
            { url: '/about', icon: 'i-cloud', name: 'could5', }
        ]
    },
    sites: [
        { url: "https://www.remove.bg/zh", title: "抠图", color: "", description: '在线抠图' },
        { url: "http://www.sortablejs.com/", title: "sortablejs", color: "", description: '功能强大的javascript拖拽库' },
        { url: "http://tool.c7sky.com/webcolor/", title: "色彩搭配表", color: "", description: '网页设计常用的色彩搭配表' },
        { url: "http://www.googlefonts.net/", title: "字体", color: "", description: '谷歌字体' },
        { url: "https://jpgmin.cn/", title: "压缩图片", color: "", description: '压图大师' },
        { url: "https://www.fontke.com/tool/rgb/eee5f8/", title: "查询颜色", color: "", description: '颜色查询' },
        { url: "https://animista.net/play/basic/rotate", title: "css动画", color: "", description: 'css动画大全' }

        
    ]
}
export default config