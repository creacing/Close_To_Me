<template>
  <div class="side pos-rel" :class="showSide ? 'open' : 'close'" v-show="showSideCopy">
    <div class="close-btn pos-abs" @click="closeSide">&lt;</div>
    <div class="links flex-col">
      <router-link class="link" :to="link.url" v-for="link of sidebar.localPath" :key="link" :class="link.name">
        <i class="ic" :class="link.icon"></i>
        <!-- <span class="count">{{ sidebar.articlesNum }}</span>
        <span class="name">文章</span>-->
      </router-link>

      <a v-for="link of sidebar.socialLinks" :key="link" :href="link.url" rel="noopener external nofollow noreferrer"
        target="_blank" class="link" :class="link.name" :title="link.url">
        <i class="ic" :class="link.icon"></i>
      </a>
    </div>
  </div>
</template>
<script setup>
import { toRefs, defineProps, watch, ref } from "vue";
import config from "../../public/config";
import { RouterLink, useRoute } from "vue-router";
//props
const props = defineProps({
  showSide: {
    type: Boolean,
    default: false,
  },
});
const { showSide } = toRefs(props);

//delay fade
const showSideCopy = ref(false)
watch(showSide, (newVal, oldVal) => {
  if (newVal) {
    showSideCopy.value = newVal
  } else {
    setTimeout(() => {
      showSideCopy.value = newVal
    }, 200)
  }

})
const { sidebar } = config;

</script>

<style lang='scss' scoped>
.close-btn {
  top: 50%;
  height: 0.725rem;
  width: 0.725rem;
  left: -0.725rem;
  background-color: #fff;
  // border-radius: 0.125rem;
}

.side {
  opacity: 0.9;
  background-image: linear-gradient(to bottom, hsl(195deg, 100%, 78%), #a29bfe);
  transition: all 0.2s ease 0s;
  // display: flex;
  // position: fixed;
  // left: 0;
  // top: 50%;
  // transform: translateY(-50%);

  // display: flex;
  // align-items: center;
  // justify-content: center;
}

@media (max-width: 991px) {
  .side {
    position: fixed;
    top: 0;
    right: 0;
    width: 0;
    height: 100%;
    z-index: 1001;
  }

  .open {
    animation: openFromRight 0.2s ease-in-out forwards;
  }

  .close {
    animation: closeFromLeft 0.2s ease-in-out forwards;
  }
}

[data-theme="dark"] .side {
  background-image: linear-gradient(#040706, #a29bfe);
  opacity: 0.9;
}

.links {
  padding: 10px;
}

.links {
  text-align: center;
}

.links .link {
  display: inline-block;
  width: 1.875rem;
  height: 1.875rem;
  line-height: 1.875rem;
  text-align: center;
  position: relative;
  overflow: hidden;
  border-radius: 38%;
}

.links .link i {
  font-size: 1.4em;
  vertical-align: middle;
  transform: scale(0.8);
}

.links .link::before {
  top: 90%;
  left: -110%;
  content: "";
  width: 120%;
  height: 120%;
  position: absolute;
  transform: rotate(45deg);
}

.links .link i,
.links .link::before {
  transition: all 0.35s cubic-bezier(0.31, -0.105, 0.43, 1.59) 0s;
}

.links .link:focus::before,
.links .link:hover::before {
  top: -10%;
  left: -10%;
}

.links .link.could::before {
  background-color: var(--color-morandi-purple);
}

.links .link.could i {
  color: var(--color-morandi-purple);
}

.links .link.could1::before {
  background-color: var(--color-could1);
}

.links .link.could1 i {
  color: var(--color-could1);
}

.links .link.could2::before {
  background-color: var(--color-could2);
}

.links .link.could2 i {
  color: var(--color-could2);
}

.links .link.could3::before {
  background-color: var(--color-could3);
}

.links .link.could3 i {
  color: var(--color-could3);
}

.links .link.could4::before {
  background-color: var(--color-could4);
}

.links .link.could4 i {
  color: var(--color-could4);
}

.links .link.could5::before {
  background-color: var(--color-could5);
}

.links .link.could5 i {
  color: var(--color-could5);
}

.links .link.github::before {
  background-color: #191717;
}

.links .link.github i {
  color: #191717;
}

.links .link.twitter::before {
  background-color: #00aff0;
}

.links .link.twitter i {
  color: #00aff0;
}

.links .link.zhihu::before {
  background-color: #1e88e5;
}

.links .link.zhihu i {
  color: #1e88e5;
}

.links .link.music::before {
  background-color: #e60026;
}

.links .link.music i {
  color: #e60026;
}

.links .link.telegram::before {
  background-color: #32afed;
}

.links .link.telegram i {
  color: #32afed;
}

.links .link.about::before {
  background-color: #3b5998;
}

.links .link.about i {
  color: #3b5998;
}

.links .link:focus i,
.links .link:hover i {
  color: var(--grey-0);
  transform: scale(1);
}
</style>

<style>
@keyframes openFromRight {
  from {
    width: 0;
  }

  to {
    width: 60%;
  }
}

@keyframes closeFromLeft {
  from {
    width: 60%;
  }

  to {
    width: 0;
  }
}
</style>